/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:25:41 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/04/04 22:23:01 by ryutaro3205      ###   ########.fr       */
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

	env = (t_fdf *)malloc(sizeof(t_fdf));
	if (!env)
		return (my_error("Failed to allocate memory\n", 2));
	if (argc == 2)
	{
		if (!init_env(env))
			return (my_error("Failed to initialize environment\n", 2));
		if (!check_argv(argv[1], env) || !init_camera(env))
		{
			ft_putstr_fd("Error\n", 2);
			exit (0);
		}
		hook_control(env);
		draw(env);
		mlx_loop(env->mlx);
	}
	return (0);
}
