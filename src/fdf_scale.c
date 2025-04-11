/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:46:54 by ehamza            #+#    #+#             */
/*   Updated: 2025/04/11 15:53:23 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_scale(t_fdf *env)
{
	double	x_scale;
	double	y_scale;
	double	scale;
	int		i;
	int		j;

	ft_max_shape(env);
	x_scale = (env->s_width / env->width);
	y_scale = (env->s_height / env->height);
	scale = ft_min(x_scale, y_scale) * 0.8;
	if (scale < 0)
		scale = 1;
	i = -1;
	while (++i < env->s_map->m_height)
	{
		j = 0;
		while (j < env->s_map->m_width)
		{
			env->s_map->point[i][j].iso_x *= scale;
			env->s_map->point[i][j].iso_y *= scale;
			ft_round(&(env->s_map->point[i][j].iso_x));
			ft_round(&(env->s_map->point[i][j].iso_y));
			j++;
		}
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
