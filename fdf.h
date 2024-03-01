/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:25:52 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/01 18:10:16 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft/includes/libft.h"
#include "minilibx_macos/mlx.h"
#include <math.h>
#include <fcntl.h>
#include <math.h>
#include <errno.h>

/*check_arg*/
int	check_argv(char *file);
int	check_extension(char *file);
int	check_line(char *line);
int	is_line_num(char *line);
/*error*/
int return_error(char *str, int ret);
/*check_num*/
int	is_number(char **arg_list);
int	collect_number(char *number);
int range_of_int(char *number);
#endif
