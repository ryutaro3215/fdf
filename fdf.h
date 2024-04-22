/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:25:52 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/04/18 15:39:24 by ryutaro3205      ###   ########.fr       */
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
# include <stdio.h>

# define WIDTH 1600
# define HEIGHT 950
# define ESCAPE 53

typedef struct s_point
{
	int					x;
	int					y;
	int					z;
	unsigned int		color;
	int					reverse;
}		t_point;

typedef struct s_map
{
	int		width;
	int		height;
	t_point	**z_matrix;
	int		z_min;
	int		z_max;
}		t_map;

typedef struct s_camera
{
	int		zoom;
	int		shift_x;
	int		shift_y;
	float	angle_x;
	float	angle_y;
	float	angle_z;
}	t_camera;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			len_size;
	int			endian;
	int			steep;
	t_map		*map;
	t_camera	*camera;
}		t_fdf;

/* initialize */
t_fdf			*init_env(void);
t_camera		*init_camera(t_fdf *env);
t_map			*init_map(void);

/* check_struct */
int				get_height(char *file, t_fdf *env);
int				count_elnum(char *line, char sep);
int				get_width(char *file, t_fdf *env, int height);
bool			check_extension(char *file);

/* check_arg */
bool			malloc_map(t_fdf *env);
void			check_argv(char *file, t_fdf *env);

/* chech_num */
int				range_of_int(char *number);
int				collect_number(char *number);
bool			eachline_num(char **split);

/* fill_map */
unsigned int	get_color(char *point);
int				get_z(char *point);
void			fill_point(int i, char **split, t_fdf *env);
bool			fill_map(char *file, t_fdf *env);

/* get_color */
unsigned int	hex_to_dec(char *hex);
int				make_rgb(int start_color, int end_color, float percent);
int				color_gradation(int	x, t_point p1, t_point p2, float gradient);

/* conversion */
void			rotate_x(int *shifted_y, int *shifted_z, float angle_x);
void			rotate_y(int *shifted_x, int *shifted_z, float angle_y);
void			rotate_z(int *shifted_x, int *shifted_y, float angle_z);
t_point			shift_point(t_point point, t_fdf *env);

/* draw */
void			put_pixel(t_fdf *env, int x, int y, int color);
void			draw_line_alg(t_point p1, t_point p2, float gradient, t_fdf *env);
void			draw_line(t_point p1, t_point p2, t_fdf *env);
void			draw(t_fdf *env);

/* draw_utils */
int				ft_abs(int a);
void			ft_swap(int *a, int *b);

/* hook */
int				close_window(t_fdf *env);
int				mouse_down(int button, t_fdf *env);
int				mouse_down(int button, t_fdf *env);
int				key_press(int keycode, t_fdf *env);
void			hook_control(t_fdf *env);
/* utils */
char			*ft_copy_to_char(char *str, char word);
void			get_min_max(t_fdf *env);
char			*rem_newline(char *line);
int				ft_max(int a, int b);

/* error */
void			my_error(char *str, int ret);
void			free_2d_array(char **array);

#endif
