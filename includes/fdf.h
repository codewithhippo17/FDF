/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:48:42 by ehamza            #+#    #+#             */
/*   Updated: 2025/04/11 15:56:02 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../includes/gnl/get_next_line.h"
# include "../includes/libft/libft.h"
# include "/usr/include/minilibx-linux/mlx.h"
# include <limits.h>
# include <math.h>
# include <stdlib.h>

# define CURRENT_D CURRENT_DIR

typedef struct s_data
{
	int				x;
	int				y;
	int				dx;
	int				dy;
	int				step_x;
	int				step_y;
	int				p;
	int				color;
	int				e2;
	int				err;
	float			dist;
	float			line_length;
	float			position;
}					t_data;

typedef struct s_img
{
	void			*mlx_img;
	char			*addr;
	int				bpp;
	int				s_line;
	int				endian;
}					t_img;

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
	double			iso_x;
	double			iso_y;
}					t_point;

typedef struct s_map
{
	t_point			**point;
	char			**line;
	int				m_height;
	int				m_width;
	int				min_isox;
	int				min_isoy;
	int				max_isox;
	int				max_isoy;
	int				valid;
}					t_map;

typedef struct s_fdf
{
	t_img			*img;
	void			*mlx;
	void			*win;
	t_map			*s_map;
	char			*ti;
	int				s_width;
	int				s_height;
	double			width;
	double			height;
}					t_fdf;

// // // //  fdf functions  \\ \\ \\ \\.

int					ft_file_format(char *filename);
t_fdf				*ft_init(const char *path);
t_fdf				*ft_parssing(int fd, t_fdf *env);
void				ft_scale(t_fdf *env);
void				ft_center(t_fdf *env);
void				ft_draw(t_fdf *env);

// // // //  parssing utils functions   \\ \\ \\ \\.

t_point				read_point(char *point, int x, int y);
void				ft_max_iso(t_map *s_map);
int					v_point(char *big);
int					get_color(char *point);
int					is_dec(char *big, int idx);
int					is_hex(char *big);
int					ft_strlenz(char *str);
void				ft_round(double *x);

// // // // memory (leaks  & kill) functions  \\ \\ \\ \\.

void				ret_error(const char *msg, t_fdf *env, int exit_code);
void				cleanup_and_exit(t_fdf *env, int exit_code);
void				ft_free_array(char **array);
void				ft_free_point(t_map *s_map);

// // // // fdf helpers functions   \\ \\ \\ \\.

void				ft_max_shape(t_fdf *env);
int					ft_min(int a, int b);

// // // // fdf utils functions   \\ \\ \\ \\.

int					handle_keypress(int keycode, t_fdf *env);
int					handle_window_close(t_fdf *env);

// // // // fdf drawing functions   \\ \\ \\ \\.

int					get_gradient_color(int start_color, int end_color,
						float position);

#endif
