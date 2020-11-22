/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 13:08:01 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/22 13:11:33 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_drawpic(t_master *m, int fd)
{
	int		x;
	int		y;

	x = 0;
	y = m->game.sh - 1;
	while (y >= 0)
	{
		while (x < m->game.sw)
		{
			ft_my_savepixel_get(m, y, x);
			write(fd, &m->input.savecolor, 3);
			write(fd, "0x00", 1);
			x++;
		}
		x = 0;
		y--;
	}
}

static void	ft_bitmapinfoheader(t_master *m, int fd)
{
	int		i;
	char	bitheader[40];

	i = 0;
	while (i < 40)
	{
		bitheader[i] = (char)(0);
		i++;
	}
	bitheader[0] = (char)(40);
	bitheader[4] = (char)(m->game.sw % 256);
	bitheader[5] = (char)(m->game.sw / 256 % 256);
	bitheader[6] = (char)(m->game.sw / 256 / 256 % 256);
	bitheader[7] = (char)(m->game.sw / 256 / 256 / 256);
	bitheader[8] = (char)(m->game.sh % 256);
	bitheader[9] = (char)(m->game.sh / 256 % 256);
	bitheader[10] = (char)(m->game.sh / 256 / 256 % 256);
	bitheader[11] = (char)(m->game.sh / 256 / 256 / 256);
	bitheader[12] = (char)(1);
	bitheader[14] = (char)(32);
	write(fd, bitheader, 40);
}

static void	ft_bitheader(t_master *m, int fd)
{
	int		i;
	char	bitheader[14];
	int		filesize;

	i = 0;
	filesize = (m->game.sw * m->game.sh * 4) + 54;
	while (i < 14)
	{
		bitheader[i] = (char)(0);
		i++;
	}
	bitheader[0] = 'B';
	bitheader[1] = 'M';
	bitheader[2] = (char)(filesize % 256);
	bitheader[3] = (char)(filesize / 256 % 256);
	bitheader[4] = (char)(filesize / 256 / 256 % 256);
	bitheader[5] = (char)(filesize / 256 / 256 / 256);
	bitheader[10] = (char)(54);
	write(fd, bitheader, 14);
}

void		ft_save(t_master *m)
{
	int		fd;

	fd = open("screenshot.bmp", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	if (fd == -1)
		ft_error(m, "Something wrong with screenshot.");
	ft_bitheader(m, fd);
	ft_bitmapinfoheader(m, fd);
	ft_drawpic(m, fd);
	close(fd);
	exit(0);
}
