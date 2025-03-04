/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:46:54 by ehamza            #+#    #+#             */
/*   Updated: 2025/03/04 01:40:25 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void    ft_max_shape(t_fdf *env)
{
	env->width = env->s_map->max_isox - env->s_map->min_isox;
	env->height = env->s_map->max_isoy - env->s_map->min_isoy;
}

// void    ft_center(t_fdf	*env)
// {
// 	int (i), (j);
	
// 	i = 0;
// 	while (i < map->m_height)
// 	{
// 		j = 0;
// 		while (j < map->m_width)
// 		{
			
// 			j++;
// 		}
// 		i++;
// 	}
// }

void    ft_scale(t_fdf *env)
{
	int (x_scale), (y_scale), (scale);
	int (i), (j);
	
	ft_max_shape(env);
	x_scale = env->s_width / env->width;
	y_scale = env->s_height / env->height;
	scale = ft_min(x_scale, y_scale) / 2;
	printf("\n%d\n", scale);
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