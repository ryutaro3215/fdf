/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:30:19 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/03/28 00:11:54 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_fdf *env)
{
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_window(env->mlx, env->win);
	free(env->camera);
	free_2d_array((void **)env->map->z_matrix);
	free(env->map);
	free(env->mlx);
	free(env);
	exit(0);
}

int	key_press(int keycode, t_fdf *env)
{
	if (keycode == ESCAPE)
		close_window(env);
	return (0);
}

void	hook_control(t_fdf *env)
{
	mlx_hook(env->win, 2, 0, key_press, env);
	mlx_hook(env->win, 17, 0, close_window, env);
}
