/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:35:46 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/04/23 14:24:55 by ryutaro3205      ###   ########.fr       */
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
	if (line == NULL)
		free_env(env, "empty file\n", 1);
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

int	count_elnum(char *line, char sep)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (line[i] != '\0')
	{
		while (line[i] == sep)
			i++;
		if (line[i] != sep && line[i] != '\0')
			count++;
		while (line[i] != sep && line[i] != '\0')
			i++;
	}
	return (count);
}

int	get_width(char *file, t_fdf *env, int height)
{
	int		width;
	int		fd;
	char	*line;
	char	*tmp;

	width = 0;
	fd = open(file, O_RDONLY);
	tmp = rem_newline(get_next_line(fd));
	line = ft_strtrim(tmp, " ");
	env->map->width = count_elnum(line, ' ');
	while (true)
	{
		width = count_elnum(line, ' ');
		free(tmp);
		free(line);
		if (width != env->map->width)
			free_env(env, "width error\n", 1);
		height--;
		if (height == 0)
			break ;
		tmp = rem_newline(get_next_line(fd));
		line = ft_strtrim(tmp, " ");
	}
	return (width);
}

bool	check_extension(char *file)
{
	char	*extension;
	int		len;

	extension = ft_strchr(file, '.');
	if (!extension)
		return (false);
	len = ft_strlen(extension);
	if (len != 4)
		return (false);
	if (ft_strncmp(extension, ".fdf", 4))
		return (false);
	return (true);
}
