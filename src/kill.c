/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:20:33 by ehamza            #+#    #+#             */
/*   Updated: 2025/02/19 14:22:20 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_free_point(t_map *s_map)
{
	int	i;

	if (!s_map || !s_map->point)
		return ;
	i = 0;
	while (i < s_map->m_height)
	{
		if (s_map->point[i])
			free(s_map->point[i]);
		i++;
	}
	free(s_map->point);
	s_map->point = NULL;
}

void	ft_free_map(t_map *s_map)
{
	if (!s_map)
		return ;
	if (s_map->line)
		ft_free_array(s_map->line);
	ft_free_point(s_map);
	free(s_map);
}

void	cleanup_and_exit(t_fdf *env)
{
	if (!env)
		return ;
	if (env->s_map)
		ft_free_map(env->s_map);
	if (env->win)
		mlx_destroy_window(env->mlx, env->win);
	if (env->mlx)
	{
		mlx_destroy_display(env->mlx);
		free(env->mlx);
	}
	free(env);
	exit(0);
}
