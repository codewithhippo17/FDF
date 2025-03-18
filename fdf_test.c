/*
int	main(int ac, char *av[])
{
	t_fdf	*env;
	int		fd;

	if (ac != 2)
		ret_error("Usage: ./fdf <filename>", NULL, 0);
	env = ft_init(av[1]);
	fd = ft_file_format(env, av[1]);
	env = ft_parssing(fd, env);

	int i = 0;
	int j = 0;

	while (i < env->s_map->m_height)
	{
		j = 0;
		while (j < env->s_map->m_width)
		{
			printf("(%d,%d) ", env->s_map->point[i][j].iso_x, env->s_map->point[i][j].iso_y);
			j++;
		}
		printf("\n");
		i++;
	}


	ft_scale(env);


	printf("\nisox_min %d\nisoy_max %d\n\n", env->s_map->min_isox, env->s_map->max_isoy);
	printf("\nisoy_min %d\nisox_max %d\n\n", env->s_map->min_isoy, env->s_map->max_isox);
	printf("\ncoordonates of the isometric projection after scaling\n\n");
	i = 0;
	while (i < env->s_map->m_height)
	{
		j = 0;
		while (j < env->s_map->m_width)
		{
			printf("(%d,%d) ", env->s_map->point[i][j].iso_x, env->s_map->point[i][j].iso_y);
			j++;
		}
		printf("\n");
		i++;
	}


	ft_center(env);


	printf("\nisox_min %d\nisoy_max %d\n\n", env->s_map->min_isox, env->s_map->max_isoy);
	printf("\nisoy_min %d\nisox_max %d\n\n", env->s_map->min_isoy, env->s_map->max_isox);
	printf("\ncoordonates of the isometric projection after centering\n\n");
	i = 0;
	while (i < env->s_map->m_height)
	{
		j = 0;
		while (j < env->s_map->m_width)
		{
			printf("(%d,%d) ", env->s_map->point[i][j].iso_x, env->s_map->point[i][j].iso_y);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");


	ft_draw(env);
	mlx_hook(env->win, 2, 1L << 0, handle_keypress, env);
	mlx_hook(env->win, 17, 1L << 17, handle_window_close, env);
	mlx_loop(env->mlx);
	cleanup_and_exit(env);
	return (0);
}
*/
