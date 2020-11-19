/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/30 10:23:10 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/19 16:13:17 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void		ft_two_back(t_master *m, int which)
{
	int		i;

	i = 0;
	if (which == 0)
	{
		while (i < m->sprite.numbsprite)
		{
			m->input.mapsplit[(int)m->sprite.sprite[i][1]][(int)m->sprite.sprite[i][0]] = '2';
			i++;
		}
	}
	i = 0;
	if (which == 1)
	{
		while (i < m->sprite.numbsprite)
		{
			m->input.mapsplit[(int)m->sprite.sprite[i][1]][(int)m->sprite.sprite[i][0]] = '0';
			i++;
		}
	}
}

int		rotate_right(t_master *m)
{
	double	oldDirX;
	double	oldPlaneX;
	double	speed;

	oldDirX = m->game.dir_x;
	oldPlaneX = m->game.plane_x;
	speed = 0.1;
	ft_two_back(m, 0);
	if (m->move.rotate_right == 1)
	{
		ft_two_back(m, 1);
		m->game.dir_x = m->game.dir_x * cos(speed) - m->game.dir_y * sin(speed);
		m->game.dir_y = oldDirX * sin(speed) + m->game.dir_y * cos(speed);
		m->game.plane_x = m->game.plane_x * cos(speed) - m->game.plane_y * sin(speed);
		m->game.plane_y = oldPlaneX * sin(speed) + m->game.plane_y * cos(speed);
		return (1);
	}
	return (0);
}

int		rotate_left(t_master *m)
{
	double	oldDirX;
	double	oldPlaneX;
	double	speed;

	oldDirX = m->game.dir_x;
	oldPlaneX = m->game.plane_x;
	speed = 0.1;
	ft_two_back(m, 0);
	if (m->move.rotate_left == 1)
	{
		ft_two_back(m, 1);
		m->game.dir_x = m->game.dir_x * cos(-speed) - m->game.dir_y * sin(-speed);
		m->game.dir_y = oldDirX * sin(-speed) + m->game.dir_y * cos(-speed);
		m->game.plane_x = m->game.plane_x * cos(-speed) - m->game.plane_y * sin(-speed);
		m->game.plane_y = oldPlaneX * sin(-speed) + m->game.plane_y * cos(-speed);
		return (1);
	}
	return (0);
}

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

int	move_rigth(t_master *m)
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

int	move_left(t_master *m)
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
