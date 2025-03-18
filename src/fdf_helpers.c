/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:36:54 by ehamza            #+#    #+#             */
/*   Updated: 2025/03/18 06:37:21 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	v_filename(char *filename)
{
	char	*tmp;
	int		len;

	len = ft_strlen(filename);
	tmp = ft_strnstr(filename, ".fdf", len);
	if (tmp && tmp[4] == '\0' && len > 4)
		return (1);
	return (0);
}

// void	ft_get_display(t_fdf *env)
// {
// 	Display	*display;

// 	display = XOpenDisplay(NULL);
// 	if (!display)
// 		ret_error("Cannot open display", env, 1);
// 	env->s_width = DisplayWidth(display, DefaultScreen(display));
// 	env->width -= env->s_width * 0.35;
// 	env->s_height = DisplayHeight(display, DefaultScreen(display));
// 	env->height -= env->s_height * 0.35;
// 	printf("\n%d\n%d\n", env->s_width, env->s_height);
// 	XCloseDisplay(display);
// }

int	ft_file_format(t_fdf *env, char *filename)
{
	char	*path;
	int		fd;

	path = ft_strjoin(CURRENT_DIR, filename);
	if (!path)
		ret_error("malloc error", env, 1);
	if (!(v_filename(filename)))
		ret_error("Invalid file name", env, 1);
	fd = open(path, O_RDONLY);
	free(path);
	if (fd == -1)
		ret_error("open error", env, 1);
	return (fd);
}

t_fdf	*ft_init_map(t_fdf *env)
{
	env->s_map = (t_map *)malloc(sizeof(t_map));
	if (env->s_map == NULL)
	{
		ret_error("malloc error", env, 1);
	}
	env->s_map->m_height = 0;
	env->s_map->m_width = 0;
	env->s_map->valid = 0;
	env->s_map->min_isox = INT_MAX;
	env->s_map->min_isoy = INT_MAX;
	env->s_map->max_isox = INT_MIN;
	env->s_map->max_isoy = INT_MIN;
	env->width = 0;
	env->height = 0;
	env->s_map->point = NULL;
	env->s_map->line = NULL;
	env->s_height = 1080;
	env->s_width = 1920;
	return (env);
}

t_fdf	*ft_init(const char *path)
{
	t_fdf	*env;

	env = (t_fdf *)malloc(sizeof(t_fdf));
	if (!env)
		ret_error("malloc error", env, 1);
	env->ti = ft_strjoin("FdF  ", path);
	env->mlx = mlx_init();
	if (!env->mlx)
		ret_error("error connecting to graphics server", env, 1);
	env = ft_init_map(env);
	env->win = mlx_new_window(env->mlx, env->s_width, env->s_height, env->ti);
	if (!env->win)
		ret_error("error initializing window", env, 1);
	env->s_height = 1000;
	env->s_width = 1000;
	free(env->ti);
	return (env);
}
