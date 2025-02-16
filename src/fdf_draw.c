/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:55:30 by ehamza            #+#    #+#             */
/*   Updated: 2025/02/16 23:55:26 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_draw_line(t_fdf *env ,t_point a, t_point b)
{
	int x;
	int y;

	x =  (a.iso_x + (env->s_width * 0.25));
	y =  (a.iso_y + (env->s_height * 0.25));
	while (x <= (b.iso_x + (env->s_width * 0.25)) && y <= (b.iso_y + (env->s_height * 0.25)))
	{
		mlx_pixel_put(env->mlx, env->win, x, y, 0xFF0000);
		x++;
		y++;
	}
}

void    ft_draw(t_fdf *env)
{
    t_point p;
    t_point p1;
    t_point p2;
    int     x;
    int     y;

    y = 0;
    while (y < env->s_map->height - 1)
    {
        x = 0;
        while (x < env->s_map->width - 1)
        {
            p = env->s_map->point[y][x];
            p1 = env->s_map->point[y][x + 1];
            p2 = env->s_map->point[y + 1][x];
            ft_draw_line(env, p, p1);
            ft_draw_line(env, p, p2);
            x++;
        }
        y++;
    }   
}

