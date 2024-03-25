/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:27:58 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/19 23:04:43 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_fdf *env, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * env->bpp / 8) + (y * env->len_size);
		env->addr[i] = color;
		env->addr[++i] = color >> 8;
		env->addr[++i] = color >> 16;
	}
}

int	ft_lerp(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

int	ft_get_color(int x, t_point p1, t_point p2, float factor)
{
	int		r;
	int		g;
	int		b;
	float	percent;

	percent = ft_abs(x - p1.x) / ft_abs(p2.x - p1.x);
	if (p1.rev)
	{
		r = ft_lerp((p2.color >> 16) & 0xFF, (p1.color >> 16) & 0xFF, percent);
		g = ft_lerp((p2.color >> 8) & 0xFF, (p1.color >> 8) & 0xFF, percent);
		b = ft_lerp(p2.color & 0xFF, p1.color & 0xFF, percent);
	}
	else
	{
		r = ft_lerp((p1.color >> 16) & 0xFF, (p2.color >> 16) & 0xFF, percent);
		g = ft_lerp((p1.color >> 8) & 0xFF, (p2.color >> 8) & 0xFF, percent);
		b = ft_lerp(p1.color & 0xFF, p2.color & 0xFF, percent);
	}
	r *= factor;
	g *= factor;
	b *= factor;
	return ((r << 16) | (g << 8) | b);
}
