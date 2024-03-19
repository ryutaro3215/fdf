/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:15:10 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/19 23:07:29 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	draw_line_loop(t_point p1, t_point p2, float grad, t_fdf *env)
{
	float	inter_y;
	int		x;

	inter_y = (int)p1.y;
	x = p1.x;
	while (x <= p2.x)
		{
			if (env->steep)
			{
				put_pixel(env, ft_ipart(inter_y), x,
					ft_get_color(x, p1, p2, ft_rfpart(inter_y)));
				put_pixel(env, ft_ipart(inter_y) + 1, x,
					ft_get_color(x, p1, p2, ft_fpart(inter_y)));
			}
			else
			{
				put_pixel(env, x, ft_ipart(inter_y),
					ft_get_color(x, p1, p2, ft_rfpart(inter_y)));
				put_pixel(env, x, ft_ipart(inter_y) + 1,
					ft_get_color(x, p1, p2, ft_fpart(inter_y)));
			}
			inter_y += grad;
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
		p1.rev = 1;
	}
	dx = (float)(p2.x - p1.x);
	dy = (float)(p2.y - p1.y);
	gradient = dy / dx;
	if (dx == 0.0f)
		gradient = 1.f;
	draw_line_loop(p1, p2, gradient, env);
}
