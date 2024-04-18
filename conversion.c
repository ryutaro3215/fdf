/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:32:55 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/04/18 13:53:15 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(int *shifted_y, int *shifted_z, float angle_x)
{
	int	previous_y;

	previous_y = *shifted_y;
	*shifted_y = previous_y * cos(angle_x) + *shifted_z * sin(angle_x);
	*shifted_z = previous_y * -sin(angle_x) + *shifted_z * cos(angle_x);
}

void	rotate_y(int *shifted_x, int *shifted_z, float angle_y)
{
	int	previous_x;

	previous_x = *shifted_x;
	*shifted_x = previous_x * cos(angle_y) + *shifted_z * sin(angle_y);
	*shifted_z = previous_x * -sin(angle_y) + *shifted_z * cos(angle_y);
}

void	rotate_z(int *shifted_x, int *shifted_y, float angle_z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *shifted_x;
	previous_y = *shifted_y;
	*shifted_x = previous_x * cos(angle_z) - previous_y * sin(angle_z);
	*shifted_y = previous_x * sin(angle_z) + previous_y * cos(angle_z);
}

t_point	shift_point(t_point point, t_fdf *env)
{
	t_point	shifted_point;

	shifted_point.x = point.x * env->camera->zoom;
	shifted_point.y = point.y * env->camera->zoom;
	shifted_point.z = point.z * env->camera->zoom;
	shifted_point.x -= (env->map->width * env->camera->zoom) / 2;
	shifted_point.y -= (env->map->height * env->camera->zoom) / 2;
	rotate_x(&shifted_point.y, &shifted_point.z, env->camera->angle_x);
	rotate_y(&shifted_point.x, &shifted_point.z, env->camera->angle_y);
	rotate_z(&shifted_point.x, &shifted_point.y, env->camera->angle_z);
	shifted_point.x += WIDTH / 2;
	shifted_point.y += HEIGHT / 2;
	shifted_point.color = point.color;
	shifted_point.reverse = 0;
	return (shifted_point);
}
