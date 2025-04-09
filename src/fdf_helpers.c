/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:58:12 by ehamza            #+#    #+#             */
/*   Updated: 2025/04/09 18:01:07 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_min(int a, int b)
{
	if (a < b)
	{
		return (a);
	}
	return (b);
}

void	ft_max_shape(t_fdf *env)
{
	ft_max_iso(env->s_map);
	env->width = env->s_map->max_isox - env->s_map->min_isox;
	env->height = env->s_map->max_isoy - env->s_map->min_isoy;
}

int	get_gradient_color(int start_color, int end_color, float position)
{
	int	r;
	int	g;
	int	b;

	if (position < 0)
		position = 0;
	else if (position > 1)
		position = 1;
	r = (int)(((start_color >> 16) & 0xFF) * (1 - position)
			+ ((end_color >> 16) & 0xFF) * position);
	g = (int)(((start_color >> 8) & 0xFF) * (1 - position)
			+ ((end_color >> 8) & 0xFF) * position);
	b = (int)((start_color & 0xFF) * (1 - position) + (end_color & 0xFF)
			* position);
	return ((r << 16) | (g << 8) | b);
}
