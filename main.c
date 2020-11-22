/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/25 15:15:23 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/22 12:10:33 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	if (ft_strncmp(extension, ".cub", 4) != 0)
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
	mlx_hook(m.vars.win, 17, 0L, close_button, &m.vars);
	mlx_hook(m.vars.win, 02, (1L << 0), key_press, &m.vars);
	mlx_loop_hook(m.vars.mlx, move, &m);
	mlx_hook(m.vars.win, 03, (1L << 1), key_release, &m.vars);
	mlx_loop(m.vars.mlx);
	return (0);
}
