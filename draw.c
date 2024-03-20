/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:19:17 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/20 17:59:43 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(int *y, int *z, float x_angle)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(x_angle) + *z * sin(x_angle);
	*z = prev_y * -sin(x_angle) + *z * cos(x_angle);
}

void	rotate_y(int *x, int *z, float y_angle)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(y_angle) + *z * sin(y_angle);
	*z = prev_x * -sin(y_angle) + *z * cos(y_angle);
}

void	rotate_z(int *x, int *y, float z_angle)
{
	t_point	prev;

	prev.x = *x;
	prev.y = *y;
	*x = prev.x * cos(z_angle) - prev.y * sin(z_angle);
	*y = prev.x * sin(z_angle) + prev.y * cos(z_angle);
}

t_point	trans(int x, int y, t_fdf *env)
{
	t_point	point;

	point.z = env->map->z_matrix[y][x].z;
	point.color = env->map->z_matrix[y][x].color;
	point.x *= env->camera->zoom;
	point.y *= env->camera->zoom;
	point.z *= env->camera->zoom / env->camera->z_height;
	// point.x -= (env->map->width * env->camera->zoom) / 2;
	// point.y -= (env->map->height * env->camera->zoom) / 2;
	rotate_x(&point.y, &point.z, env->camera->x_angle);
	rotate_y(&point.x, &point.z, env->camera->y_angle);
	rotate_z(&point.x, &point.y, env->camera->z_angle);
	point.x += WIDTH / 2 + env->camera->x_offset;
	point.y += (HEIGHT + env->map->height / 2 * env->camera->zoom) / 2
		+ env->camera->y_offset;
	return (point);
}

void	draw(t_fdf *env)
{
	int		x;
	int		y;

	ft_bzero(env->addr, WIDTH * HEIGHT * (env->bpp / 8));
	y = 0;
	while (y < env->map->height && y >= 0)
	{
		x = 0;
		while (x < env->map->width && x >= 0)
		{
			if (x != env->map->width - 1)
				draw_line(trans(x, y, env), trans(x + 1, y, env), env);
			if (y != env->map->height - 1)
				draw_line(trans(x, y, env), trans(x, y + 1, env), env);
			x += 1;
		}
		y += 1;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
