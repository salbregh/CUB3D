/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   more_movement.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 10:16:01 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/20 11:03:43 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_two_back(t_master *m, int which)
{
	int		i;

	i = 0;
	if (which == 0)
	{
		while (i < m->sprite.numb)
		{
			m->input.mapsplit[(int)m->sprite.sprite[i][1]]
			[(int)m->sprite.sprite[i][0]] = '2';
			i++;
		}
	}
	i = 0;
	if (which == 1)
	{
		while (i < m->sprite.numb)
		{
			m->input.mapsplit[(int)m->sprite.sprite[i][1]]
			[(int)m->sprite.sprite[i][0]] = '0';
			i++;
		}
	}
}

int		rotate_right(t_master *m)
{
	double	olddir_x;
	double	oldplane_x;
	double	speed;

	olddir_x = m->game.dir_x;
	oldplane_x = m->game.plane_x;
	speed = 0.1;
	ft_two_back(m, 0);
	if (m->move.rotate_right == 1)
	{
		ft_two_back(m, 1);
		m->game.dir_x = m->game.dir_x * cos(speed) - m->game.dir_y * sin(speed);
		m->game.dir_y = olddir_x * sin(speed) + m->game.dir_y * cos(speed);
		m->game.plane_x = m->game.plane_x * cos(speed) -
		m->game.plane_y * sin(speed);
		m->game.plane_y = oldplane_x * sin(speed) +
		m->game.plane_y * cos(speed);
		return (1);
	}
	return (0);
}

int		rotate_left(t_master *m)
{
	double	olddir_x;
	double	oldplane_x;
	double	speed;

	olddir_x = m->game.dir_x;
	oldplane_x = m->game.plane_x;
	speed = 0.1;
	ft_two_back(m, 0);
	if (m->move.rotate_left == 1)
	{
		ft_two_back(m, 1);
		m->game.dir_x = m->game.dir_x * cos(-speed) -
		m->game.dir_y * sin(-speed);
		m->game.dir_y = olddir_x * sin(-speed) +
		m->game.dir_y * cos(-speed);
		m->game.plane_x = m->game.plane_x * cos(-speed) -
		m->game.plane_y * sin(-speed);
		m->game.plane_y = oldplane_x * sin(-speed) +
		m->game.plane_y * cos(-speed);
		return (1);
	}
	return (0);
}
