/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:48:42 by ehamza            #+#    #+#             */
/*   Updated: 2025/03/18 07:35:55 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../includes/ft_printf/libftprintf.h"
# include "../includes/gnl/get_next_line.h"
# include "../includes/libft/libft.h"
# include "/usr/include/minilibx-linux/mlx.h"
# include <X11/Xlib.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>

# define CURRENT_D CURRENT_DIR

typedef struct point
{
	int		x;
	int		y;
	int		z;
	int		color;
	int		iso_x;
	int		iso_y;
}			t_point;

typedef struct s_map
{
	t_point	**point;
	char	**line;
	int		m_height;
	int		m_width;
	int		min_isox;
	int		min_isoy;
	int		max_isox;
	int		max_isoy;
	int		valid;

}			t_map;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	t_map	*s_map;
	char	*data_addr;
	char	*ti;
	int		s_width;
	int		s_height;
	int		width;
	int		height;
}			t_fdf;

// // // //  fdf functions  \\ \\ \\ \\.

t_fdf		*ft_init(const char *path);

// // // //  parssing functions   \\ \\ \\ \\.

t_fdf		*ft_parssing(int fd, t_fdf *env);
t_map		*ft_read_file(int fd, t_map *s_map);
t_map		*calc_shape(t_map *s_map);
t_map		*read_map(t_map *s_map, int height, int width);

// // // //  parssing utils functions   \\ \\ \\ \\.

t_point		read_point(char *point, int x, int y);
void		ft_max_iso(t_map *s_map);
int			v_point(char *big);
int			get_color(char *point);
int			is_dec(char *big, int idx);
int			is_hex(char *big);
int			ft_strlenz(char *str);
int			ft_round(double x);

// // // // memory leaks functions   \\ \\ \\ \\.

void		ft_free_array(char **array);
void		ft_free_point(t_map *s_map);
void		ft_free_map(t_map *s_map);
void		cleanup_and_exit(t_fdf *env);

// // // // fdf helpers functions   \\ \\ \\ \\.

int			v_filename(char *filename);
int			ft_file_format(t_fdf *env, char *filename);
t_fdf		*ft_init_map(t_fdf *env);

// // // // fdf utils functions   \\ \\ \\ \\.

int			handle_keypress(int keycode, t_fdf *env);
int			handle_window_close(t_fdf *env);
void		ret_error(const char *msg, t_fdf *env, int exit_code);
int			ft_min(int a, int b);

// // // // fdf scaling functions   \\ \\ \\ \\.

void		ft_center(t_fdf *env);
void		ft_scale(t_fdf *env);

// // // // fdf drawing functions   \\ \\ \\ \\.

void		ft_draw(t_fdf *env);

#endif