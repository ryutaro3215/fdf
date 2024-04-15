/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:19:17 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/04/10 22:34:28 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(float *shifted_y, float *shifted_z, t_fdf *env)
{
	float	previous_y;

	previous_y = *shifted_y;
	*shifted_y = previous_y * cos(env->camera->angle_x) + *shifted_z * sin(env->camera->angle_x);
	*shifted_z = previous_y * -sin(env->camera->angle_x) + *shifted_z * cos(env->camera->angle_x);
}

void	rotate_y(float *shifted_x, float *shifted_z, t_fdf *env)
{
	float	previous_x;

	previous_x = *shifted_x;
	*shifted_x = previous_x * cos(env->camera->angle_y) + *shifted_z * sin(env->camera->angle_y);
	*shifted_z = previous_x * -sin(env->camera->angle_y) + *shifted_z * cos(env->camera->angle_y);
}

void	rotate_z(float *shifted_x, float *shifted_y, t_fdf *env)
{
	float	previous_x;
	float	previous_y;

	previous_x = *shifted_x;
	previous_y = *shifted_y;
	*shifted_x = previous_x * cos(env->camera->angle_z) - previous_y * sin(env->camera->angle_z);
	*shifted_y = previous_x * sin(env->camera->angle_z) + previous_y * cos(env->camera->angle_z);
}

t_shifted	shift_point(t_point point, t_fdf *env)
{
	t_shifted	shifted_point;

	shifted_point.sx = point.x * env->camera->zoom;
	shifted_point.sy = point.y * env->camera->zoom;
	shifted_point.sz = point.z * env->camera->zoom;
	rotate_x(&shifted_point.sy, &shifted_point.sz, env);
	rotate_y(&shifted_point.sx, &shifted_point.sz, env);
	rotate_z(&shifted_point.sx, &shifted_point.sy, env);
	shifted_point.sx += env->camera->shift_x;
	shifted_point.sy += env->camera->shift_y;
	shifted_point.color = point.color;
	return (shifted_point);
}

void	draw_xline(t_shifted point1, t_shifted point2, t_fdf *env)
{
	char		*dst;
	float		dx;
	float		dy;
	float		steep;

	dx = point2.sx - point1.sx;
	dy = point2.sy - point1.sy;
	steep = dy / dx;
	while (((int)point1.sx < (int)point2.sx))
	{
		dst = env->addr + ((int)point1.sy * env->len_size + (int)point1.sx * (env->bpp / 8));
		*(unsigned int *)dst = point1.color;
		point1.sx += 0.1;
		point1.sy += 0.1 * steep;
	}
}

void	draw_yline(t_shifted point1, t_shifted point2, t_fdf *env)
{
	char		*dst;
	float		dx;
	float		dy;
	float		steep;

	dx = point2.sx - point1.sx;
	dy = point2.sy - point1.sy;
	steep = dx / dy;
	while (((int)point1.sy < (int)point2.sy))
	{
		dst = env->addr + ((int)point1.sy * env->len_size + (int)point1.sx * (env->bpp / 8));
		*(unsigned int *)dst = point1.color;
		point1.sy += 0.1;
		point1.sx += 0.1 * steep;
	}
}

void	draw(t_fdf *env)
{
	int	x;
	int	y;

	y = 0;
	while (y < env->map->height)
	{
		x = 0;
		while (x < env->map->width)
		{
			if (x < env->map->width - 1)
				draw_xline(shift_point(env->map->z_matrix[y][x], env),
					shift_point(env->map->z_matrix[y][x + 1], env) , env);
			if (y < env->map->height - 1)
				draw_yline(shift_point(env->map->z_matrix[y][x], env),
					shift_point(env->map->z_matrix[y + 1][x], env), env);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
