/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:25:52 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/09 14:12:06 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/includes/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <stdbool.h>

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}		t_point;

typedef struct s_map
{
	int		width;
	int		height;
	t_point	**z_matrix;
	int		z_min;
	int		z_max;
}		t_map;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		len_size;
	int		endian;
	int		steep;
	t_map	*map;
}		t_fdf;

/*initialize*/
bool	init_map(t_fdf *env);
bool	init_env(t_fdf *env);

/*check argument*/
bool	check_argv(char *file, t_fdf *env);
bool	check_extension(char *file);
bool	check_lines(char *file, t_fdf *env);
int		get_width(char *file, t_fdf *env);
void	get_each_width(int fd, char *line, char **split, t_fdf *env);
int		get_height(char *file, t_fdf *env);
bool	lines_num(char *file);
char	**make_split(int fd);
bool	eachline_num(char **split);
int		collect_number(char *number);
int 	range_of_int(char *number);
bool	fill_map(char *file, t_fdf *env);
void	fill_point(int i, char **split, t_fdf *env);

/*error*/
int		my_error(char *str, int ret);
void	free_2d_array(void **array);
void	free_matrix(t_fdf *env);
/*utils*/
char	*ft_copy_to_char(char *str, char word);
int		hex_to_dec(char *hex_string);

#endif
