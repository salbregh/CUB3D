/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/30 10:23:10 by salbregh      #+#    #+#                 */
/*   Updated: 2020/12/02 23:46:10 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int		move_up(t_master *m)
{
	float	speed;

	ft_two_back(m, 0);
	speed = 0.1;
	if (m->move.up == 1)
	{
		if (m->input.mapsplit[(int)(m->game.pos_y + (m->game.dir_y * speed))]
			[(int)(m->game.pos_x + (m->game.dir_x * speed))] == '0')
		{
			ft_two_back(m, 1);
			m->game.pos_x = m->game.pos_x + m->game.dir_x * speed;
			m->game.pos_y = m->game.pos_y + m->game.dir_y * speed;
			return (1);
		}
	}
	return (0);
}

int		move_down(t_master *m)
{
	float	speed;

	ft_two_back(m, 0);
	speed = 0.1;
	if (m->move.down == 1)
	{
		if (m->input.mapsplit[(int)(m->game.pos_y - (m->game.dir_y * speed))]
			[(int)(m->game.pos_x - (m->game.dir_x * speed))] == '0')
		{
			ft_two_back(m, 1);
			m->game.pos_x = m->game.pos_x - m->game.dir_x * speed;
			m->game.pos_y = m->game.pos_y - m->game.dir_y * speed;
			return (1);
		}
	}
	return (0);
}

int		move_rigth(t_master *m)
{
	float	speed;

	ft_two_back(m, 0);
	speed = 0.1;
	if (m->move.right == 1)
	{
		if (m->input.mapsplit[(int)(m->game.pos_y + (m->game.plane_y * speed))]
		[(int)(m->game.pos_x + (m->game.plane_x * speed))] == '0')
		{
			ft_two_back(m, 1);
			m->game.pos_x += m->game.plane_x * speed;
			m->game.pos_y += m->game.plane_y * speed;
			return (1);
		}
	}
	return (0);
}

int		move_left(t_master *m)
{
	float	speed;

	ft_two_back(m, 0);
	speed = 0.1;
	if (m->move.left == 1)
	{
		if (m->input.mapsplit[(int)(m->game.pos_y - (m->game.plane_y * speed))]
		[(int)(m->game.pos_x - (m->game.plane_x * speed))] == '0')
		{
			ft_two_back(m, 1);
			m->game.pos_x -= m->game.plane_x * speed;
			m->game.pos_y -= m->game.plane_y * speed;
			return (1);
		}
	}
	return (0);
}
