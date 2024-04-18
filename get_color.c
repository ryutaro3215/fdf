/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:55:45 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/04/18 00:36:41 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	hex_to_dec(char *hex_string)
{
	unsigned int	decimal_value;
	int				i;
	int				digit_value;
	char			c;

	decimal_value = 0;
	i = -1;
	digit_value = 0;
	while (hex_string[++i] != '\0')
	{
		c = hex_string[i];
		if (c >= '0' && c <= '9')
			digit_value = c - '0';
		else if (c >= 'A' && c <= 'F')
			digit_value = c - 'A' + 10;
		else if (c >= 'a' && c <= 'f')
			digit_value = c - 'a' + 10;
		decimal_value = decimal_value * 16 + digit_value;
	}
	return (decimal_value);
}

int	make_rgb(int start_color, int end_color, float percent)
{
	if (start_color == end_color)
		return (start_color);
	return ((int)(start_color + (end_color - start_color) * percent));
}

int color_gradation(int x, t_point p1, t_point p2, float gradient)
{
	float percent;
	int r, g, b;

	if (p2.x != p1.x)
		percent = (float)(x - p1.x) / (float)(p2.x - p1.x);
	else
		percent = 0;
	if (gradient < 0)
		gradient = (1 + gradient);
	r = make_rgb((p1.color >> 16) & 0xFF, (p2.color >> 16) & 0xFF, percent);
	g = make_rgb((p1.color >> 8) & 0xFF, (p2.color >> 8) & 0xFF, percent);
	b = make_rgb((p1.color) & 0xFF, (p2.color) & 0xFF, percent);
	return ((int)(r * gradient) << 16) | ((int)(g * gradient) << 8) | (int)(b * gradient);
}
