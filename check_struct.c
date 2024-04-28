/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:35:46 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/04/28 22:32:31 by rmatsuba         ###   ########.fr       */
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
		if (line[i] != sep && line[i] != '\0')
		{
			count++;
			while (line[i] != sep && line[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	*make_remedline(int fd)
{
	char	*return_line;
	char	*before_line;

	before_line = get_next_line(fd);
	if (check_newline(before_line) == true)
		return_line = rem_newline(before_line);
	else
		return_line = before_line;
	return (return_line);
}

int	get_width(char *file, t_fdf *env, int height)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	line = make_remedline(fd);
	env->map->width = count_elnum(line, ' ');
	free(line);
	while (height > 1)
	{
		line = make_remedline(fd);
		width = count_elnum(line, ' ');
		free(line);
		if (width != env->map->width)
		{
			close(fd);
			free_env(env, "Invalid map width\n", 1);
		}
		height--;
	}
	close(fd);
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
