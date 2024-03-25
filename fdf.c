/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:25:41 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/25 23:12:26 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q fdf");
// }

int	main(int argc, char **argv)
{
	t_fdf	*env;

	env = (t_fdf *)malloc(sizeof(t_fdf));
	if (!env)
		return (my_error("Failed to allocate memory\n", 2));
	if (argc == 2)
	{
		if (!init_env(env))
			return (my_error("Failed to initialize environment\n", 2));
		if (!check_argv(argv[1], env))
		{
			free_env(env);
			return (my_error("Invalid argument\n", 2));
		}
		if (!init_camera(env))
		{
			free_env(env);
			return (my_error("Failed to allocate memory\n", 2));
		}
		hook_control(env);
		draw(env);
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
		mlx_loop(env->mlx);
	}
	return (0);
}
