/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:19:17 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/15 20:50:44 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

t_point	converter(float x, float y, t_fdf *env)
{
	t_point	point;

	point.x *= env->camera->zoom;
	point.y *= env->camera->zoom;
	point.x += env->camera->shift_x;
	point.y += env->camera->shift_y;
	point.color = env->map->z_matrix[(int)y][(int)x].color;
	return (point);
}

void	draw_line(t_point p1, t_point p2, t_fdf *env)
{
	char	*dst;

	dst = env->addr + ((int)p1.y * env->len_size) + (int)p1.x * (env->bpp / 8);
}

void	draw(t_map *map, t_fdf *env)
{
	int	x;
	int	y;

	ft_bzero(env->addr, WIDTH * HEIGHT * (env->bpp / 8));
	y = 0;
	while (y < env->map->height)
	{
		x = 0;
		while (x < env->map->width)
		{
			if (x < env->map->width - 1)
				draw_line(converter(x, y, env), converter(x + 1, y, env), env);
			if (y < env->map->height - 1)
				draw_line(converter(x, y, env), converter(x, y + 1, env), env);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
