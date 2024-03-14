/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:35:46 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/10 20:12:28 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file, t_fdf *env)
{
	int		height;
	int		fd;
	char	*line;

	height = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		height++;
		line = get_next_line(fd);
	}
	env->map->height = height;
	close(fd);
	return (env->map->height);
}

void	get_each_width(int fd, char *line, char **split, t_fdf *env)
{
	int		width;

	while (true)
	{
		width = 0;
		free(line);
		free_2d_array((void **)split);
		line = get_next_line(fd);
		if (line == NULL)
			return ;
		split = ft_split(line, ' ');
		while (split[width] != NULL)
			width++;
		if (width != env->map->width)
		{
			free(line);
			free_2d_array((void **)split);
			env->map->width = -1;
			return ;
		}
	}
}

int	get_width(char *file, t_fdf *env)
{
	int		width;
	int		fd;
	char	**split;
	char	*line;

	width = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	split = ft_split(line, ' ');
	while (split[width] != NULL)
		width++;
	env->map->width = width;
	get_each_width(fd, line, split, env);
	close(fd);
	return (env->map->width);
}
