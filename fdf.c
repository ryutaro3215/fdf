/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:25:41 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/08 00:00:18 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

__attribute__((destructor))
static void destructor() {
    system("leaks -q fdf");
}

int main(int argc, char **argv)
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
			free(env->map);
			free(env);
			return (my_error("Invalid argument\n", 2));
		}
		
		free_2d_array((void **)env->map->z_matrix);
		free(env->map);
		free(env);
	}
	return (0);
}