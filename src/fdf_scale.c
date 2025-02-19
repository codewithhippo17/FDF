/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:46:54 by ehamza            #+#    #+#             */
/*   Updated: 2025/02/19 18:59:23 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"



// t_fdf    *ft_scale(t_fdf *env)
// {
//     int (scale), (i), (j);

//     i = 0;
//     scale = ft_min(env->width / env->s_map->max_isox, env->height / env->s_map->max_isoy);
//     while (i < env->s_map->m_height)
//     {
//         j = 0;
//         while (j < env->s_map->m_width)
//         {
//             env->s_map->point[i][j].iso_x *= scale;
//             env->s_map->point[i][j].iso_y *= scale;
//             j++;
//         }
//         i++;
//     }
//     return (env);
// }
