/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:55:30 by ehamza            #+#    #+#             */
/*   Updated: 2025/03/04 01:39:54 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


// void    ft_draw_line(t_fdf env, t_point p, t_point p1)
// {
//     int x;
//     int y;

//     int x1;
//     int y1;
//     while (p.iso_x < p1.iso_x)
//     {

//         x = p.iso_x;
//         y = p.iso_y;
//         mlx_pixel_put(env.mlx, env.win, p.iso_x, p.iso_y, p.color);
//     }
    
// }

void ft_draw(t_fdf *env)
{
    int (i), (j);
	i = 0;
	
	while (i < env->s_map->m_height)
	{
		j = 0;
		while (j < env->s_map->m_width)
		{
			// if (env->s_map->point[i][j].iso_x > 0 && env->s_map->point[i][j].iso_y > 0)
			// {
				mlx_pixel_put(env->mlx, env->win, env->s_map->point[i][j].iso_x + 970, env->s_map->point[i][j].iso_y + 540, 0xffffff);
			// }
			
			j++;
		}
		i++;
	}
}

