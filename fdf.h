/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:25:52 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/20 19:08:32 by ryutaro3205      ###   ########.fr       */
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

# define WIDTH 1020
# define HEIGHT 960
# define ESCAPE 53

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
	bool	end_point;
	int		rev;
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
	float	x_angle;
	float	y_angle;
	float	z_angle;
	float	z_height;
	int		x_offset;
	int		y_offset;
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

/*initialize*/
bool	init_env(t_fdf *env);
bool	init_map(t_fdf *env);
bool	init_camera(t_fdf *env);

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
bool	malloc_map(t_fdf *env);
bool	fill_map(char *file, t_fdf *env);
void	fill_point(int i, char **split, t_fdf *env);

/*draw*/
void	draw(t_fdf *env);
void	draw_line(t_point p1, t_point p2, t_fdf *env);
t_point	trans(int x, int y, t_fdf *env);
void	rotate_x(int *y, int *z, float x_angle);
void	rotate_y(int *x, int *z, float y_angle);
void	rotate_z(int *x, int *y, float z_angle);

/*draw_utils*/
int		ft_min(int a, int b);
float	ft_abs(float n);
int		ft_ipart(float n);
float	ft_fpart(float n);
float	ft_rfpart(float n);

/*draw_pixel*/
void	put_pixel(t_fdf *env, int x, int y, int color);
int		ft_lerp(int first, int second, double p);
int		ft_get_color(int x, t_point s, t_point e, float factor);

/*draw_line*/
void	ft_swap(int *a, int *b);
void	draw_line_loop(t_point p1, t_point p2, float grad, t_fdf *env);


/*hook*/
void	hook_control(t_fdf *env);
int		key_press(int keycode, t_fdf *env);
int		close_window(t_fdf *env);
/*error*/
int		my_error(char *str, int ret);
void	free_2d_array(void **array);
void	free_map(t_point ***map);
void	free_env(t_fdf *env);
/*utils*/
char	*ft_copy_to_char(char *str, char word);
int		hex_to_dec(char *hex_string);
void	get_min_max(t_fdf *env);
int		ft_min(int a, int b);

#endif
