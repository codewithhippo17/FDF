/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:36:54 by ehamza            #+#    #+#             */
/*   Updated: 2025/04/09 18:46:42 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	v_filename(char *filename)
{
	char	*tmp;
	int		len;

	len = ft_strlen(filename);
	tmp = ft_strnstr(filename, ".fdf", len);
	if (tmp && tmp[4] == '\0' && len > 4)
		return (1);
	return (0);
}

static void	ft_init_img(t_fdf *env)
{
	env->img = (t_img *)malloc(sizeof(t_img));
	if (!env->img)
		ret_error("Error: Malloc failed\n", env, 1);
	env->img->mlx_img = mlx_new_image(env->mlx, env->s_width, env->s_height);
	if (!env->img->mlx_img)
		ret_error("Error: Couldn't creates  a new image in memory\n", env, 1);
	env->img->addr = mlx_get_data_addr(env->img->mlx_img, &(env->img->bpp),
			&(env->img->s_line), &(env->img->endian));
}

static t_fdf	*ft_init_map(t_fdf *env)
{
	env->s_map = (t_map *)malloc(sizeof(t_map));
	if (env->s_map == NULL)
	{
		ret_error("Error: Malloc failed\n", env, 1);
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
	env->s_height = 1020;
	env->s_width = 1020;
	return (env);
}

t_fdf	*ft_init(const char *path)
{
	t_fdf	*env;

	env = (t_fdf *)malloc(sizeof(t_fdf));
	if (!env)
		ret_error("Error: Malloc failed\n", env, 1);
	env->ti = ft_strjoin("FdF  ", path);
	if (!env->ti)
		ret_error("Error: Malloc failed\n", env, 1);
	env->mlx = mlx_init();
	if (!env->mlx)
		ret_error("error connecting to graphics server\n", env, 1);
	env = ft_init_map(env);
	env->win = mlx_new_window(env->mlx, env->s_width, env->s_height, env->ti);
	if (!env->win)
		ret_error("error initializing window\n", env, 1);
	ft_init_img(env);
	return (env);
}

int	ft_file_format(char *filename)
{
	char	*path;
	int		fd;

	path = ft_strjoin(CURRENT_D, filename);
	if (!path)
		return (perror("malloc"), -1);
	if (!(v_filename(filename)))
	{
		write(2, "Invalid file name\n", 18);
		free(path);
		return (-1);
	}
	fd = open(path, O_RDONLY);
	free(path);
	if (fd == -1)
		perror("open");
	return (fd);
}
