/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:25:41 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/04/23 01:22:46 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

__attribute__((destructor))
static void destructor() {
    system("leaks -q fdf");
}

int	main(int argc, char **argv)
{
	t_fdf	*env;

	if (argc == 2)
	{
		env = init_env();
		if (!env || !check_extension(argv[1]))
			my_error("env Error\n", 1);
		env->map = init_map();
		if (!env->map)
			my_error("map Error\n", 1);
		check_argv(argv[1], env);
		env->camera = init_camera(env);
		draw(env);
		hook_control(env);
		mlx_loop(env->mlx);
	}
	else
		my_error("Invalid argument number\n", 1);
	return (0);
}
