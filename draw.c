/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:19:17 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/19 17:07:31 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_abs(float n)
{
	if (n < 0)
		return (-n);
	return (n);
}

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void	isometric(float *x, float *y, int z, t_fdf *env)
{
	float	previous_x;
	float	previous_y;

	(void)env;
	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void	draw_line(float x, float y, float x1, float y1, t_fdf *env)
{
	float	dx;
	float	dy;
	int		max;
	int		z;
	int		z1;

	z = env->map->z_matrix[(int)y][(int)x].z;
	z1 = env->map->z_matrix[(int)y1][(int)x1].z;

	x *= env->camera->zoom;
	y *= env->camera->zoom;
	x1 *= env->camera->zoom;
	y1 *= env->camera->zoom;

	isometric(&x, &y, z, env);
	isometric(&x1, &y1, z1, env);

	x += env->camera->shift_x;
	y += env->camera->shift_y;
	x1 += env->camera->shift_x;
	y1 += env->camera->shift_y;

	dx = x1 - x;
	dy = y1 - y;
	max = ft_max(ft_abs(dx), ft_abs(dy));
	dx /= max;
	dy /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(env->mlx, env->win, x, y, 0x00FF00);
		x += dx;
		y += dy;
	}
}

void	draw(t_fdf *env)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	ft_bzero(env->addr, WIDTH * HEIGHT * (env->bpp / 8));
	while (y < env->map->height)
	{
		x = 0;
		while (x < env->map->width)
		{
			if (x < env->map->width - 1)
				draw_line(x, y, x + 1, y, env);
			if (y < env->map->height - 1)
				draw_line(x, y, x, y + 1, env);
			x++;
		}
		y++;
	}
}
