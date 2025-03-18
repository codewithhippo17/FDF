/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:55:30 by ehamza            #+#    #+#             */
/*   Updated: 2025/03/18 03:44:51 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw(t_fdf *env)
{
	int	i;
	int	j;

	i = 0;
	while (i < env->s_map->m_height)
	{
		j = 0;
		while (j < env->s_map->m_width)
		{
			mlx_pixel_put(env->mlx, env->win,
				env->s_map->point[i][j].iso_x,
				env->s_map->point[i][j].iso_y, 0xffffff);
			j++;
		}
		i++;
	}
}
