/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/25 15:15:23 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/20 10:09:37 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// static void		struct_check(t_master *m)
// {
// 	printf("screenheigth: %i\n", m->game.screenheight);
// 	printf("screenwidth: %i\n", m->game.screenwidth);
// 	printf("pos_x: %f\n", m->game.pos_x);
// 	printf("pos_y: %f\n", m->game.pos_y);
// 	printf("pos: %c\n", m->game.pos);
// 	printf("dir_x: %f\n", m->game.dir_x);
// 	printf("dir_y: %f\n", m->game.dir_y);
// 	printf("plane_x: %f\n", m->game.plane_x);
// 	printf("plane_y: %f\n", m->game.plane_y);
// 	printf("camera_x: %f\n", m->game.camera_x);
// 	printf("raydir_x: %f\n", m->game.raydir_x);
// 	printf("raydir_y: %f\n", m->game.raydir_y);
// 	printf("map_x: %i\n", m->game.map_x);
// 	printf("map_y: %i\n", m->game.map_y);
// 	printf("sidedist_x: %f\n", m->game.sidedist_x);
// 	printf("sidedist_y: %f\n", m->game.sidedist_y);
// 	printf("deltadist_x: %f\n", m->game.deltadist_x);
// 	printf("deltadist_y: %f\n", m->game.deltadist_y);
// 	printf("perpwalldist: %f\n", m->game.perpwalldist);
// 	printf("step_x: %i\n", m->game.step_x);
// 	printf("step_y: %i\n", m->game.step_y);
// 	printf("side: %i\n", m->game.side);
// }

static void		more_main(t_master *m, int argc, char **argv)
{
	int			fd;
	char		*extension;
	
	if (argc == 3)
	{
		if ((ft_strncmp(argv[2], "--save", 7) != 0))
			ft_error(m, "Second argument is not save.");
		m->input.save = 1;
	}
	else if (argc != 2 && m->input.save == 0)
		ft_error(m, "Invalid amount of arguments.");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error(m, "Problem with opening file");
	extension = ft_substr(argv[1], ft_strlen(argv[1]) - 4, ft_strlen(argv[1]));
	if (ft_strncmp(extension,".cub", 4) != 0)
		ft_error(m, "No .cub extension");
	free(extension);
	ft_get_input(fd, m);
	close(fd);
}

int				main(int argc, char **argv)
{
	t_master	m;

	ft_sort_master(&m);
	more_main(&m, argc, argv);
	m.vars.mlx = mlx_init();
	m.vars.win = mlx_new_window(m.vars.mlx, m.game.sw, m.game.sh, "CUB3D");
	ft_start_raycasting(&m);
	system("leaks cub3D");
	mlx_hook(m.vars.win, 17, 0L, close_button, &m.vars);
	mlx_hook(m.vars.win, 02, (1L << 0), key_press, &m.vars);
	mlx_loop_hook(m.vars.mlx, move, &m);
	mlx_hook(m.vars.win, 03, (1L << 1), key_release, &m.vars);
	mlx_loop(m.vars.mlx);
	return (0);
}
