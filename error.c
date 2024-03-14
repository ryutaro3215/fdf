/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:09:13 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/14 11:41:37 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	my_error(char *str, int ret)
{
	ft_putstr_fd(str, ret);
	return (ret);
}

void	free_map(t_point ***map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != NULL)
		{
			free(map[i][j]);
			j++;
		}
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_2d_array(void **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_env(t_fdf *env)
{
	free_2d_array((void **)env->map->z_matrix);
	free(env->map);
	free(env->camera);
	free(env->mlx);
	free(env->win);
	free(env->img);
	free(env->addr);
	free(env);
}
