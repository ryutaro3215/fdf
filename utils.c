/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:10:46 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/14 16:46:53 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**make_split(int fd)
{
	char	*line;
	char	*trimed_line;
	char	**split;

	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	trimed_line = ft_strtrim(line, "\n");
	split = ft_split(trimed_line, ' ');
	free(line);
	free(trimed_line);
	return (split);
}

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

int	hex_to_dec(char *hex_string)
{
	int		decimal_value;
	int		i;
	int		digit_value;
	char	c;

	decimal_value = 0;
	i = 0;
	digit_value = 0;
	while (hex_string[i] != '\0')
	{
		c = hex_string[i];
		if (c >= '0' && c <= '9')
			digit_value = c - '0';
		else if (c >= 'A' && c <= 'F')
			digit_value = c - 'A' + 10;
		else if (c >= 'a' && c <= 'f')
			digit_value = c - 'a' + 10;
		decimal_value = decimal_value * 16 + digit_value;
		i++;
	}
	return (decimal_value);
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
