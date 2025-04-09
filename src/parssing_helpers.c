/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 23:27:03 by ehamza            #+#    #+#             */
/*   Updated: 2025/04/07 23:20:52 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_round(double *x)
{
	*x = round(*x);
}

int	ft_strlenz(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ',')
	{
		i++;
	}
	return (i);
}

t_point	read_point(char *point, int x, int y)
{
	t_point	s_point;

	if (!point)
		return ((t_point){0});
	s_point.x = x;
	s_point.y = y;
	s_point.z = ft_atoi(point);
	s_point.color = get_color(ft_strchr(point, ','));
	s_point.iso_x = ((x + s_point.z) / sqrt(2));
	s_point.iso_y = ((x - s_point.z + 2 * y) / sqrt(6));
	return (s_point);
}

void	ft_max_iso(t_map *s_map)
{
	int	i;
	int	j;

	i = 0;
	while (i < s_map->m_height)
	{
		j = 0;
		while (j < s_map->m_width)
		{
			if (s_map->min_isox > s_map->point[i][j].iso_x)
				s_map->min_isox = s_map->point[i][j].iso_x;
			if (s_map->max_isoy < s_map->point[i][j].iso_y)
				s_map->max_isoy = s_map->point[i][j].iso_y;
			if (s_map->min_isoy > s_map->point[i][j].iso_y)
				s_map->min_isoy = s_map->point[i][j].iso_y;
			if (s_map->max_isox < s_map->point[i][j].iso_x)
				s_map->max_isox = s_map->point[i][j].iso_x;
			j++;
		}
		i++;
	}
}
