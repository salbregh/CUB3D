/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/09 16:52:58 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/15 20:53:46 by salbregh      ########   odam.nl         */
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

static void		ft_check_more_position(t_master *m)
{
	if (m->game.pos == 'N')
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

static void		ft_check_position(t_master *m)
{
	if (m->game.pos == 'W')
	{
		m->game.dir_x = -1;
		m->game.dir_y = 0;
		m->game.plane_x = 0;
		m->game.plane_y = -0.66;
	}
	else if (m->game.pos == 'E')
	{
		m->game.dir_x = 1;
		m->game.dir_y = 0;
		m->game.plane_x = 0;
		m->game.plane_y = 0.66;
	}
	else
		ft_check_more_position(m);
}

static void		ft_start_position(t_master *m, int x, int y)
{
	m->input.maplines = ft_maplines(m);
	while (y < m->input.maplines)
	{
		while (m->input.mapsplit[y][x] != '\0')
		{
			if (m->input.mapsplit[y][x] == 'N' || m->input.mapsplit[y][x] == 'S'
			|| m->input.mapsplit[y][x] == 'E' || m->input.mapsplit[y][x] == 'W')
			{
				if (m->game.pos_x != 0 || m->game.pos_y != 0)
					ft_error(m, "multiple players in cub map");
				m->game.pos_x = x + 0.5;
				m->game.pos_y = y + 0.5;
				m->game.pos = m->input.mapsplit[y][x];
				m->input.mapsplit[y][x] = '0';
			}
			if (m->input.mapsplit[y][x] == '2')
				m->sprite.numbsprite++;
			x++;
		}
		y++;
		x = 0;
	}
}

void			ft_check_input(t_master *m)
{
	ft_start_position(m, 0, 0);
	if (m->game.pos_x == 0 || m->game.pos_y == 0)
		ft_error(m, "no player found in cub map");
	ft_validate_map(m);
	ft_check_position(m);
}
