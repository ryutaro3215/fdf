/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:01:09 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/04 18:57:45 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_line_num(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (!(ft_isdigit(line[0]) || line[0] == '-'))
			return (0);
		if (line[i] == ' ' && line[i + 1] == ' ')
			return (0);
		if (line[i] == ' ' || ft_isdigit(line[i]) || line[i] == '-' || line[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_line(char *line)
{
	char 	**splited_line;
	char	*tmp;
	int		flag;

	if (!is_line_num(line))
		return (0);
	tmp = ft_strtrim(line, "\n");
	splited_line = ft_split(tmp, ' ');
	if (!is_number(splited_line))
		flag = 0;
	else
		flag = 1;
	free(tmp);
	free_array(splited_line);
	return (flag);
}

int	check_extension(char *file)
{
	int	i;

	i = 0;
	while (file[i + 1] != '\0')
		i++;
	if (file[i] == 'f' && file[i - 1] == 'd' && file[i - 2] == 'f' && file[i - 3] == '.')
		return (1);
	return (0);
}

int	check_argv(char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line != NULL)
	{
		if (!check_line(line))
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}
