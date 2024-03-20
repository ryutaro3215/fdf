/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:37:13 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/20 16:38:54 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool	init_map(t_fdf *env)
{
	env->map = (t_map *)malloc(sizeof(t_map));
	if (!env->map)
		return (false);
	env->map->width = 0;
	env->map->height = 0;
	env->map->z_matrix = NULL;
	env->map->z_min = 0;
	env->map->z_max = 0;
	return (true);
}

bool	init_camera(t_fdf *env)
{
	env->camera = (t_camera *)malloc(sizeof(t_camera));
	if (!env->camera)
		return (false);
	env->camera->zoom = ft_min(WIDTH / env->map->width / 2,
			HEIGHT / env->map->height / 2);
	env->camera->x_angle = -0.615472907;
	env->camera->y_angle = -0.523599;
	env->camera->z_angle = 0.615472907;
	env->camera->z_height = 1;
	env->camera->x_offset = 0;
	env->camera->y_offset = 0;
	return (true);
}

bool	init_env(t_fdf *env)
{
	env->mlx = mlx_init();
	if (!env->mlx)
		return (false);
	env->win = mlx_new_window(env->mlx, 1020, 960, "FDF");
	if (!env->win)
		return (false);
	env->img = mlx_new_image(env->mlx, 1020, 960);
	if (!env->img)
		return (false);
	env->addr = mlx_get_data_addr(env->img, &env->bpp,
			&env->len_size, &env->endian);
	if (!env->addr)
		return (false);
	if (!init_map(env))
		return (false);
	return (true);
}
