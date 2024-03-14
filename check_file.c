/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:14:12 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/14 16:57:32 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool	check_extension(char *file)
{
	char	*extension;

	extension = ft_strchr(file, '.');
	if (!extension)
		return (false);
	if (ft_strncmp(extension, ".fdf", 4))
		return (false);
	return (true);
}

void	fill_point(int i, char **split, t_fdf *env)
{
	int		j;

	j = 0;
	while (j < env->map->width)
	{
		env->map->z_matrix[i][j].x = j;
		env->map->z_matrix[i][j].y = i;
		env->map->z_matrix[i][j].z = ft_atoi(split[j]);
		if (ft_strchr(split[j], ',') != NULL)
			env->map->z_matrix[i][j].color = hex_to_dec(ft_strchr(split[j], ','));
		else
			env->map->z_matrix[i][j].color = 0xFFFFFF;
		env->map->z_matrix[i][j].end_point = false;
		j++;
	}
	env->map->z_matrix[i][j].x = 0;
	env->map->z_matrix[i][j].y = 0;
	env->map->z_matrix[i][j].z = 0;
	env->map->z_matrix[i][j].color = 0;
	env->map->z_matrix[i][j].end_point = true;
}
