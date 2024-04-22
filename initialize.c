/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:37:13 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/04/18 22:44:20 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->width = 0;
	map->height = 0;
	map->z_matrix = NULL;
	map->z_min = 0;
	map->z_max = 1;
	return (map);
}

t_camera	*init_camera(t_fdf *env)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		return (NULL);
	camera->zoom = ft_max(WIDTH / env->map->width / 2,
			HEIGHT / env->map->height / 2);
	if (camera->zoom <= 0)
		camera->zoom = 1;
	camera->shift_x = (WIDTH - camera->zoom * env->map->width) / 2;
	camera->shift_y = (HEIGHT - camera->zoom * env->map->height) / 2;
	camera->angle_x = -35.264 * M_PI / 180;
	camera->angle_y = -35.264 * M_PI / 180;
	camera->angle_z = 35.264 * M_PI / 180;
	return (camera);
}

t_fdf	*init_env(void)
{
	t_fdf	*env;

	env = (t_fdf *)malloc(sizeof(t_fdf));
	env->mlx = mlx_init();
	if (!env->mlx)
		return (NULL);
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "FDF");
	if (!env->win)
		return (NULL);
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (!env->img)
		return (NULL);
	env->addr = mlx_get_data_addr(env->img, &env->bpp,
			&env->len_size, &env->endian);
	if (!env->addr)
		return (NULL);
	return (env);
}
