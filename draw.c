/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:19:17 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/18 19:14:50 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	draw_xline(t_point p1, t_point p2, t_fdf *env)
{
	int		p1x;
	int		p1y;
	int		p2x;
	int		dx;
	char	*dst;

	dst = NULL;
	p1x = p1.x * env->camera->zoom;
	p1y = p1.y * env->camera->zoom;
	p2x = p2.x * env->camera->zoom;
	p1x += env->camera->shift_x;
	p1y += env->camera->shift_y;
	p2x += env->camera->shift_x;
	dx = ft_abs(p2x - p1x);
	dx /= ft_abs(p2x - p1x);
	while ((p2x - p1x))
	{
		dst = env->addr + (p1y * env->len_size + (p1x * (env->bpp / 8)));
		*(unsigned int *)dst = 0x00ff00;
		p1x += dx;
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
				draw_line(env->map->z_matrix[y][x], env->map->z_matrix[y][x + 1], env);
			if (y < env->map->height - 1)
				draw_line(env->map->z_matrix[y][x], env->map->z_matrix[y + 1][x], env);
			x++;
		}
		y++;
	}
}
