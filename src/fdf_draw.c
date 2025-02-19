/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:55:30 by ehamza            #+#    #+#             */
/*   Updated: 2025/02/19 18:44:55 by ehamza           ###   ########.fr       */
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
    t_point p;
    int     x;
    int     y;

    y = 0;
    while (y < env->s_map->m_height)
    {
        x = 0;
        while (x < env->s_map->m_width)
        {
            p = env->s_map->point[y][x];
            mlx_pixel_put(env->mlx, env->win, p.iso_x, p.iso_y, 0xff0000);
            x++;
        }
        y++;
    }   
}

