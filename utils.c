/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:10:46 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/04/18 11:55:47 by ryutaro3205      ###   ########.fr       */
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
	return (remed_str);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
