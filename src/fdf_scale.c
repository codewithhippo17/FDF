/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:46:54 by ehamza            #+#    #+#             */
/*   Updated: 2025/03/18 07:30:06 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_max_shape(t_fdf *env)
{
	ft_max_iso(env->s_map);
	env->width = env->s_map->max_isox - env->s_map->min_isox;
	env->height = env->s_map->max_isoy - env->s_map->min_isoy;
}

void	ft_scale(t_fdf *env)
{
	int	x_scale;
	int	y_scale;
	int	scale;
	int	i;
	int	j;

	ft_max_shape(env);
	x_scale = (env->s_width / env->width);
	y_scale = (env->s_height / env->height);
	scale = ft_min(x_scale, y_scale);
	printf("\nscale : %d\n", scale);
	i = 0;
	while (i < env->s_map->m_height)
	{
		j = 0;
		while (j < env->s_map->m_width)
		{
			env->s_map->point[i][j].iso_x *= scale;
			env->s_map->point[i][j].iso_y *= scale;
			j++;
		}
		i++;
	}
}

void	ft_center(t_fdf *env)
{
	int	trans_x;
	int	trans_y;
	int	i;
	int	j;

	i = 0;
	ft_max_shape(env);
	trans_x = env->s_width / 2;
	trans_y = env->s_height / 2;
	trans_x -= env->s_map->max_isox - env->width / 2;
	trans_y -= env->s_map->max_isoy - env->height / 2;
	printf("\ntransx %d\ntransy %d\n", trans_x, trans_y);
	while (i < env->s_map->m_height)
	{
		j = 0;
		while (j < env->s_map->m_width)
		{
			env->s_map->point[i][j].iso_x += trans_x;
			env->s_map->point[i][j].iso_y += trans_y;
			j++;
		}
		i++;
	}
}
