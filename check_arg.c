/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:07:52 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/04/22 21:43:34 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool	malloc_map(t_fdf *env)
{
	int	i;

	env->map->z_matrix = (t_point **)malloc(sizeof(t_point *)
			* (env->map->height + 1));
	if (!env->map->z_matrix)
		return (false);
	i = -1;
	while (++i < env->map->height)
	{
		env->map->z_matrix[i] = (t_point *)malloc(sizeof(t_point)
				* (env->map->width + 1));
		if (!env->map->z_matrix[i])
		{
			while (i >= 0)
				free(env->map->z_matrix[i--]);
			free(env->map);
			return (false);
		}
		if (i == env->map->height - 1)
			env->map->z_matrix[++i] = NULL;
	}
	return (true);
}

void	check_argv(char *file, t_fdf *env)
{
	int		width;
	int		height;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		my_error("file error\n", 1);
	height = get_height(file, env);
	width = get_width(file, env, height);
	if ((width <= 1 && height <= 1) || width == -1)
		my_error("file error\n", 1);
	if (!malloc_map(env))
		my_error("malloc_map failed\n", 1);
	if (!fill_map(file, env))
		my_error("fill_map failed\n", 1);
	get_min_max(env);
}
