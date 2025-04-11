/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:34:41 by ehamza            #+#    #+#             */
/*   Updated: 2025/04/09 17:56:43 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_keypress(int keycode, t_fdf *env)
{
	if (keycode == 65307)
	{
		mlx_loop_end(env->mlx);
		return (1);
	}
	return (0);
}

int	handle_window_close(t_fdf *env)
{
	mlx_loop_end(env->mlx);
	return (0);
}
