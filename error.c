/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:09:13 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/04/23 14:22:40 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_error(char *str, int ret)
{
	ft_putstr_fd(str, ret);
	exit (-1);
}

void	free_env(t_fdf *env, char *str, int errnum)
{
	if (env->img)
		mlx_destroy_image(env->mlx, env->img);
	if (env->win)
		mlx_destroy_window(env->mlx, env->win);
	if (env->mlx)
		free(env->mlx);
	if (env->camera)
		free(env->camera);
	if (env->map)
		free(env->map);
	if (env->camera)
		free(env->camera);
	if (env)
		free(env);
	my_error(str, errnum);
}

void	free_2d_array(char **array)
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
