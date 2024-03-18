/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:19:17 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/18 17:40:53 by ryutaro3205      ###   ########.fr       */
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

void	draw_yline(t_point p1, t_point p2, t_fdf *env)
{
	int		p1x;
	int		p1y;
	int		p2y;
	int		dy;
	char	*dst;

	dst = NULL;
	p1x = p1.x * env->camera->zoom;
	p1y = p1.y * env->camera->zoom;
	p2y = p2.y * env->camera->zoom;
	p1x += env->camera->shift_x;
	p1y += env->camera->shift_y;
	p2y += env->camera->shift_y;
	dy = ft_abs(p2y - p1y);
	dy /= ft_abs(p2y - p1y);
	while ((p2y - p1y))
	{
		dst = env->addr + (p1y * env->len_size + (p1x * (env->bpp / 8)));
		*(unsigned int *)dst = 0xFF0000;
		p1y += dy;
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
				draw_xline(env->map->z_matrix[y][x], env->map->z_matrix[y][x + 1], env);
			if (y < env->map->height - 1)
				draw_yline(env->map->z_matrix[y][x], env->map->z_matrix[y + 1][x], env);
			x++;
		}
		y++;
	}
}
