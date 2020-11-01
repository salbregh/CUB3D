/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/09 16:52:58 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/01 18:24:43 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int		ft_maplines(t_master *m)
{
	int		i;

	i = 0;
	while (m->input.mapsplit[i])
		i++;
	return (i);
}

static void		ft_check_position(t_master *m)
{
	if (m->game.pos == 'E')
	{
		m->game.dir_x = 1;
		m->game.dir_y = 0;
		m->game.plane_x = 0;
		m->game.plane_y = -0.66;
	}
	else if (m->game.pos == 'W')
	{
		m->game.dir_x = -1;
		m->game.dir_y = 0;
		m->game.plane_x = 0;
		m->game.plane_y = -0.66;
	}
	else if (m->game.pos == 'N')
	{
		m->game.dir_x = 0;
		m->game.dir_y = -1;
		m->game.plane_x = 0.66;
		m->game.plane_y = 0;
	}
	else if (m->game.pos == 'S')
	{
		m->game.dir_x = 0;
		m->game.dir_y = 1;
		m->game.plane_x = -0.66;
		m->game.plane_y = 0;
	}
}

static int		ft_start_position(t_master *m)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < ft_maplines(m))
	{
		while (m->input.mapsplit[y][x] != '\0')
		{
			if (m->input.mapsplit[y][x] == 'N' || m->input.mapsplit[y][x] == 'S'
			|| m->input.mapsplit[y][x] == 'E' || m->input.mapsplit[y][x] == 'W')
			{
				if (m->game.pos_x != 0 || m->game.pos_y != 0)
					return (-1);
				m->game.pos_x = x + 0.5;
				m->game.pos_y = y + 0.5;
				m->game.pos = m->input.mapsplit[y][x];
				m->input.mapsplit[y][x] = '0';
			}
			x++;
		}
		y++;
		x = 0;
	}
	ft_check_position(m);
	return (0);
}

int		ft_check_input(t_master *m)
{
	if (ft_start_position(m) == -1 || m->game.pos_x == 0 || m->game.pos_y == 0)
		return (-1);
	if (ft_validate_map(m) == -1)
		return (-1);
	return (0);
}
