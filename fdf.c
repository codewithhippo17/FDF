/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 09:12:10 by ehamza            #+#    #+#             */
/*   Updated: 2025/04/09 18:45:22 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char *av[])
{
	t_fdf	*env;
	int		fd;

	env = NULL;
	if (ac != 2)
		ret_error("Usage: ./fdf <filename>\n", NULL, 1);
	fd = ft_file_format(av[1]);
	if (fd == -1)
		return (1);
	env = ft_init(av[1]);
	env = ft_parssing(fd, env);
	ft_scale(env);
	ft_center(env);
	ft_draw(env);
	mlx_hook(env->win, 2, 65307, handle_keypress, env);
	mlx_hook(env->win, 17, 131072, handle_window_close, env);
	mlx_loop(env->mlx);
	cleanup_and_exit(env, 0);
}
