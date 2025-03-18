/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:34:41 by ehamza            #+#    #+#             */
/*   Updated: 2025/03/18 03:06:19 by ehamza           ###   ########.fr       */
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

void	ret_error(const char *msg, t_fdf *env, int exit_code)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	cleanup_and_exit(env);
	exit(exit_code);
}

int	ft_min(int a, int b)
{
	if (a < b)
	{
		return (a);
	}
	return (b);
}
