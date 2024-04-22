/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:30:19 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/04/22 20:40:48 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_fdf *env)
{
	int	i;

	i = -1;
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_window(env->mlx, env->win);
	free(env->camera);
	while (env->map->z_matrix[++i])
		free(env->map->z_matrix[i]);
	free(env->map->z_matrix);
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

// int	my_mouse_down(int button, t_fdf *env)
// {
// 	if (button == MOUSE_WHEEL_DOWN)
// 	{
// 		if (env->camera->zoom >= 800)
// 			return (0);
// 		else
// 		{
// 			env->camera->zoom += 1;
// 			draw(env);
// 		}
// 	}
// 	return (0);
// }

// int	my_mouse_up(int button, t_fdf *env)
// {
// 	if (button == MOUSE_WHEEL_UP)
// 	{
// 		if (env->camera->zoom <= 1)
// 			return (0);
// 		else
// 		{
// 			env->camera->zoom -= 1;
// 			draw(env);
// 		}
// 	}
// 	return (0);
// }

void	hook_control(t_fdf *env)
{
	mlx_hook(env->win, 2, 0, key_press, env);
	mlx_hook(env->win, 17, 0, close_window, env);
}
