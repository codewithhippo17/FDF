/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 09:12:10 by ehamza            #+#    #+#             */
/*   Updated: 2025/03/18 08:07:44 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char *av[])
{
	t_fdf	*env;
	int		fd;

	if (ac != 2)
		ret_error("Usage: ./fdf <filename>", NULL, 0);
	env = ft_init(av[1]);
	fd = ft_file_format(env, av[1]);
	env = ft_parssing(fd, env);
	ft_scale(env);
	ft_center(env);
	ft_draw(env);
	mlx_hook(env->win, 2, 1L << 0, handle_keypress, env);
	mlx_hook(env->win, 17, 1L << 17, handle_window_close, env);
	mlx_loop(env->mlx);
	cleanup_and_exit(env);
	return (0);
}
