/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:19:17 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/14 11:46:18 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	draw(t_fdf *env)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < env->map->height)
// 	{
// 		j = 0;
// 		while (j < env->map->width)
// 		{
// 			if (j < env->map->width - 1)
// 				draw_line(env->map->z_matrix[i][j], env->map->z_matrix[i][j + 1], env);
// 			if (i < env->map->height - 1)
// 				draw_line(env->map->z_matrix[i][j], env->map->z_matrix[i + 1][j], env);
// 			j++;
// 		}
// 		i++;
// 	}
// }
