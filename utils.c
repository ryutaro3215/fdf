/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:10:46 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/04/28 22:31:56 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_copy_to_char(char *str, char word)
{
	int		i;
	int		j;
	char	*copy;

	i = 0;
	while (str[i] != word)
	{
		if (str[i] == '\0')
			return (ft_strdup(str));
		i++;
	}
	copy = (char *)malloc(sizeof(char) * (i + 1));
	if (!copy)
		return (NULL);
	j = 0;
	while (i > 0)
	{
		copy[j] = str[j];
		i--;
		j++;
	}
	copy[i] = '\0';
	return (copy);
}

void	get_min_max(t_fdf *env)
{
	int	i;
	int	j;

	i = 0;
	while (i < env->map->height)
	{
		j = 0;
		while (j < env->map->width)
		{
			if (env->map->z_matrix[i][j].z > env->map->z_max)
				env->map->z_max = env->map->z_matrix[i][j].z;
			if (env->map->z_matrix[i][j].z < env->map->z_min)
				env->map->z_min = env->map->z_matrix[i][j].z;
			j++;
		}
		i++;
	}
}

char	*rem_newline(char *line)
{
	int		len;
	char	*remed_str;
	int		i;

	len = 0;
	i = 0;
	while (line[len] != '\0' && line[len] != '\n')
		len++;
	remed_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!remed_str)
		my_error("malloc failed\n", 1);
	while (i < len)
	{
		remed_str[i] = line[i];
		i++;
	}
	remed_str[i] = '\0';
	free(line);
	return (remed_str);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

bool	check_newline(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (true);
		i++;
	}
	return (false);
}
