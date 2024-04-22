/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:35:46 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/04/22 20:02:38 by ryutaro3205      ###   ########.fr       */
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

	width = 0;
	fd = open(file, O_RDONLY);
	line = ft_strtrim(rem_newline(get_next_line(fd)), " ");
	env->map->width = count_elnum(line, ' ');
	while (true)
	{
		width = count_elnum(line, ' ');
		if (width != env->map->width)
			my_error("Invalid map width\n", 1);
		free(line);
		height--;
		if (height == 0)
			break ;
		line = ft_strtrim(rem_newline(get_next_line(fd)), " ");;
	}
	return	(width);
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
