/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:55:50 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/04/22 21:45:05 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_z(char *point)
{
	char	**num_and_color;
	int		z;

	if (ft_strchr(point, ',') == NULL)
	{
		if (collect_number(point) == false)
			my_error("Invalid number in map\n", 1);
		z = ft_atoi(point);
	}
	else
	{
		num_and_color = ft_split(point, ',');
		if (collect_number(num_and_color[0]) == false)
			my_error("Invalid number in map\n", 1);
		z = ft_atoi(num_and_color[0]);
		free_2d_array(num_and_color);
	}
	return (z);
}

unsigned int	get_color(char *point)
{
	char			**num_and_color;
	unsigned int	color;

	if (ft_strchr(point, ',') == NULL)
		color = 0xffffff;
	else
	{
		num_and_color = ft_split(point, ',');
		color = hex_to_dec(num_and_color[1]);
		free_2d_array(num_and_color);
	}
	return (color);
}

void	fill_point(int i, char **split, t_fdf *env)
{
	int		j;

	j = 0;
	while (j < env->map->width)
	{
		env->map->z_matrix[i][j].x = j;
		env->map->z_matrix[i][j].y = i;
		env->map->z_matrix[i][j].z = get_z(split[j]);
		env->map->z_matrix[i][j].color = get_color(split[j]);
		j++;
	}
}

bool	fill_map(char *file, t_fdf *env)
{
	int		fd;
	char	*remed_line;
	char	*tmp;
	char	**split;
	int		i;

	i = -1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (false);
	while (++i < env->map->height)
	{
		tmp = rem_newline(get_next_line(fd));
		remed_line = ft_strtrim(tmp, " ");
		free(tmp);
		split = ft_split(remed_line, ' ');
		free(remed_line);
		fill_point(i, split, env);
		free_2d_array(split);
	}
	close(fd);
	return (true);
}
