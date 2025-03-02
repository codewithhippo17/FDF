/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:46:54 by ehamza            #+#    #+#             */
/*   Updated: 2025/03/02 15:56:52 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_render(t_map *map)
{
	int (i),(j);
	
	i = 0;
	while (i < map->m_height)
	{
		j = 0;
		while (j < map->m_width)
		{
			map->point[i][j].iso_x -= map->min_isox;
			map->point[i][j].iso_y -= map->max_isoy;
			map->point[i][j].iso_y *= -1;
			j++;
		}
		i++;
	}
}

void    ft_max_shape(t_fdf *env)
{
	int (i), (j);
	i = 0;
	while (i < env->s_map->m_height)
	{
		j = 0;
		while (j < env->s_map->m_width)
		{
			if (env->width < env->s_map->point[i][j].iso_x)
			{
				env->width = env->s_map->point[i][j].iso_x;
			}
			if (env->height < env->s_map->point[i][j].iso_y)
			{
				env->height = env->s_map->point[i][j].iso_y;
			}
			j++;
		}
		i++;
	}
	
}

void    ft_scale(t_fdf *env)
{
	int (x_scale), (y_scale), (scale);
	int (i), (j);
	
	ft_max_shape(env);
	x_scale = env->s_width / env->width;
	y_scale = env->s_height / env->height;
	scale = ft_min(x_scale, y_scale) / 10;
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