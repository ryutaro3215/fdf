/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intialize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:37:13 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/07 23:59:11 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool	init_env(t_fdf *env)
{
	env->mlx = mlx_init();
	if (!env->mlx)
		return (false);
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "FDF");
	env->map = (t_map *)malloc(sizeof(t_map));
	if (!env->map)
		return (false);
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (!env->img)
		return (false);
	env->addr = mlx_get_data_addr(env->img, &env->bpp, &env->len_size, &env->endian);
	if (!env->addr)
		return (false);
	return (true);
}
