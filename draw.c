/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:19:17 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/25 22:34:27 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_dot(t_point point, t_fdf *env)
{
	char	*dst;

	point.x *= env->camera->zoom;
	point.y *= env->camera->zoom;

	point.x += env->camera->shift_x;
	point.y += env->camera->shift_y;

	dst = env->addr + (point.y * env->len_size + point.x * (env->bpp / 8));
	*(unsigned int *)dst = 0xffff00;
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
			draw_dot(env->map->z_matrix[y][x], env);
			x++;
		}
		y++;
	}
}
