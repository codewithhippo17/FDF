/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:17:04 by ehamza            #+#    #+#             */
/*   Updated: 2025/04/09 18:29:10 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	*ft_read_file(int fd, t_map *s_map)
{
	char	*result;
	char	*current;
	char	*temp;

	result = get_next_line(fd);
	if (!result)
		return (s_map);
	current = get_next_line(fd);
	while (current != NULL)
	{
		temp = result;
		result = ft_strjoin(temp, current);
		if (!result)
			return (free(result), free(current), s_map);
		free(current);
		current = get_next_line(fd);
		free(temp);
	}
	free(current);
	s_map->line = ft_split(result, '\n');
	free(result);
	if (!s_map->line)
		return (s_map);
	close(fd);
	return (s_map->valid = 1, s_map);
}

static t_map	*calc_shape(t_map *s_map)
{
	char	**split;
	int		checker;

	s_map->m_height = 0;
	checker = 0;
	while (s_map->line[s_map->m_height] != NULL)
	{
		split = ft_split(s_map->line[s_map->m_height], ' ');
		if (!split)
			return (s_map->valid = 0, s_map);
		if (checker == 0)
		{
			while (split[checker])
				checker++;
		}
		s_map->m_width = 0;
		while (split[s_map->m_width])
			s_map->m_width++;
		if (checker != s_map->m_width)
			return (ft_free_array(split), s_map->valid = 0, s_map);
		s_map->m_height++;
		ft_free_array(split);
	}
	s_map->valid = 2;
	return (s_map);
}

static t_map	*v_cordz(t_map *s_map)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s_map->line[i])
	{
		split = ft_split(s_map->line[i], ' ');
		if (!split)
			return (s_map->valid = 0, s_map);
		j = 0;
		while (split[j])
		{
			if (!(v_point(split[j])))
				return (s_map->valid = 0, ft_free_array(split), s_map);
			j++;
		}
		ft_free_array(split);
		i++;
	}
	return (s_map->valid = 3, s_map);
}

static t_map	*read_map(t_map *s_map, int height, int width)
{
	char	**points;
	int		x;
	int		y;

	y = 0;
	s_map->point = (t_point **)malloc(sizeof(t_point *) * height);
	if (!s_map->point)
		return (s_map->valid = 0, s_map);
	while (y < height)
	{
		s_map->point[y] = (t_point *)malloc(sizeof(t_point) * width);
		if (!s_map->point[y])
			return (ft_free_point(s_map), s_map->valid = 0, s_map);
		points = ft_split(s_map->line[y], ' ');
		x = 0;
		while (x < width)
		{
			s_map->point[y][x] = read_point(points[x], x, y);
			x++;
		}
		ft_free_array(points);
		y++;
	}
	return (s_map->valid = 5, s_map);
}

t_fdf	*ft_parssing(int fd, t_fdf *env)
{
	env->s_map = ft_read_file(fd, env->s_map);
	if (env->s_map->valid == 1)
	{
		env->s_map = calc_shape(env->s_map);
		if (env->s_map->valid == 2)
		{
			env->s_map = v_cordz(env->s_map);
			if (env->s_map->valid == 3)
			{
				env->s_map = read_map(env->s_map, env->s_map->m_height,
						env->s_map->m_width);
			}
		}
	}
	if (env->s_map->valid != 5)
		ret_error("Map error", env, 1);
	return (env);
}
