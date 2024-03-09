/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:09:13 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/07 23:59:36 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	my_error(char *str, int ret)
{
	ft_putstr_fd(str, ret);
	return (ret);
}

void	free_matrix(t_fdf *env)
{
	int	i;

	i = 0;
	while (i < env->map->height)
	{
		free(env->map->z_matrix[i]);
		i++;
	}
	free(env->map->z_matrix);
}

void	free_env(t_fdf *env)
{
	free_matrix(env);
	free(env->map);
	free(env);
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
