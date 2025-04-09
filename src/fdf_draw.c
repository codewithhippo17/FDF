/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:55:30 by ehamza            #+#    #+#             */
/*   Updated: 2025/04/09 18:00:40 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	get_position(float dist, float line_length)
{
	if (line_length > 0)
		return (dist / line_length);
	return (0);
}

static void	my_putpixel(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	if (x < 0 || y < 0)
		return ;
	i = img->bpp - 8;
	pixel = img->addr + (y * img->s_line + x * img->bpp / 8);
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

static t_data	ft_draw_init(t_point pi, t_point pf)
{
	t_data	data;

	data.dx = abs((int)(pf.iso_x - pi.iso_x));
	data.dy = abs((int)(pf.iso_y - pi.iso_y));
	data.step_x = -1;
	if (pi.iso_x < pf.iso_x)
		data.step_x = 1;
	data.step_y = -1;
	if (pi.iso_y < pf.iso_y)
		data.step_y = 1;
	data.err = -(data.dy) / 2;
	if (data.dx > data.dy)
		data.err = data.dx / 2;
	data.line_length = sqrtf(data.dx * data.dx + data.dy * data.dy);
	data.x = (int)pi.iso_x;
	data.y = (int)pi.iso_y;
	data.e2 = 0;
	data.position = 0;
	return (data);
}

static void	ft_drawline(t_fdf *env, t_point pi, t_point pf)
{
	t_data	data;

	data = ft_draw_init(pi, pf);
	while (1)
	{
		data.dist = sqrtf(pow(data.x - pi.iso_x, 2) + pow(data.y - pi.iso_y,
					2));
		data.position = get_position(data.dist, data.line_length);
		data.color = get_gradient_color(pi.color, pf.color, data.position);
		my_putpixel(env->img, data.x, data.y, data.color);
		if (data.x == (int)pf.iso_x && data.y == (int)pf.iso_y)
			break ;
		data.e2 = data.err;
		if (data.e2 > -(data.dx))
		{
			data.err -= data.dy;
			data.x += data.step_x;
		}
		if (data.e2 < data.dy)
		{
			data.err += data.dx;
			data.y += data.step_y;
		}
	}
}

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
			if (j < env->s_map->m_width - 1)
				ft_drawline(env, env->s_map->point[i][j], env->s_map->point[i][j
					+ 1]);
			if (i < env->s_map->m_height - 1)
				ft_drawline(env, env->s_map->point[i][j], env->s_map->point[i
					+ 1][j]);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img->mlx_img, 0, 0);
}
