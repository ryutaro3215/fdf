/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:19:17 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/04/22 20:38:11 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_fdf *env, int x, int y, int color)
{
	int		dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = (x * env->bpp / 8) + (y * env->len_size);
		env->addr[dst] = color;
		env->addr[++dst] = color >> 8;
		env->addr[++dst] = color >> 16;
	}
}

void	draw_line_alg(t_point p1, t_point p2, float gradient, t_fdf *env)
{
	float	fp1_y;
	int		x;

	fp1_y = (float)p1.y;
	x = p1.x;
	while (x <= p2.x)
	{
		if (env->steep)
		{
			put_pixel(env, (int)fp1_y, x,
				color_gradation(x, p1, p2, gradient));
		}
		else
		{
			put_pixel(env, x, (int)fp1_y,
				color_gradation(x, p1, p2, gradient));
		}
		fp1_y += gradient;
		x++;
	}
}

void	draw_line(t_point p1, t_point p2, t_fdf *env)
{
	float	dx;
	float	dy;
	float	gradient;

	env->steep = ft_abs(p2.y - p1.y) > ft_abs(p2.x - p1.x);
	if (env->steep)
	{
		ft_swap(&p1.x, &p1.y);
		ft_swap(&p2.x, &p2.y);
	}
	if (p1.x > p2.x)
	{
		ft_swap(&p1.x, &p2.x);
		ft_swap(&p1.y, &p2.y);
		p1.reverse = 1;
	}
	dx = (float)(p2.x - p1.x);
	dy = (float)(p2.y - p1.y);
	gradient = dy / dx;
	if (dx == 0.0f)
		gradient = 1.f;
	draw_line_alg(p1, p2, gradient, env);
}

void	draw(t_fdf *env)
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
				draw_line(shift_point(env->map->z_matrix[y][x], env),
					shift_point(env->map->z_matrix[y][x + 1], env), env);
			if (y < env->map->height - 1)
				draw_line(shift_point(env->map->z_matrix[y][x], env),
					shift_point(env->map->z_matrix[y + 1][x], env), env);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
