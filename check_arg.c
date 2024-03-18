/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:07:52 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/14 17:54:41 by rmatsuba         ###   ########.fr       */
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
			free_2d_array((void **)env->map->z_matrix);
			free(env->map);
			return (false);
		}
		env->map->z_matrix[i + 1] = NULL;
	}
	env->map->z_min = 0;
	env->map->z_max = 0;
	return (true);
}

bool	fill_map(char *file, t_fdf *env)
{
	int		fd;
	char	*line;
	char	**split;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (false);
	i = -1;
	while (++i < env->map->height)
	{
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		free(line);
		fill_point(i, split, env);
		free_2d_array((void **)split);
	}
	if (close(fd) == -1)
		return (false);
	return (true);
}

bool	lines_num(char *file)
{
	int		fd;
	char	**split;

	fd = open(file, O_RDONLY);
	while (true)
	{
		split = make_split(fd);
		if (split == NULL)
			break ;
		if (!eachline_num(split))
		{
			free_2d_array((void **)split);
			return (false);
		}
		free_2d_array((void **)split);
	}
	if (close(fd) == -1)
		return (false);
	return (true);
}

bool	check_lines(char *file, t_fdf *env)
{
	int	width;
	int	height;

	width = get_width(file, env);
	height = get_height(file, env);
	if ((width <= 1 && height <= 1) || width == -1)
		return (false);
	if (!lines_num(file))
		return (false);
	if (!malloc_map(env))
		return (false);
	if (!fill_map(file, env))
		return (false);
	return (true);
}

bool	check_argv(char *file, t_fdf *env)
{
	if (!check_extension(file))
		return (false);
	if (!check_lines(file, env))
		return (false);
	get_min_max(env);
	return (true);
}
