/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/30 10:23:10 by salbregh      #+#    #+#                 */
/*   Updated: 2020/10/24 17:45:41 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

// int	rotate_right(t_master *m)
// {
// 	double		rotate_speed;
// 	double		old_dir;
// 	double		old_plane;

// 	// add if statement to stop it from looking ?
// 	rotate_speed = 0.1;
// 	old_dir = m->game.dir_x;
// 	m->game.dir_x = m->game.dir_x * cos(rotate_speed) - m->game.dir_y * sin(rotate_speed);
// 	m->game.dir_y = old_dir * sin(-rotate_speed) + m->game.dir_y * cos(-rotate_speed);
// 	old_plane = m->game.plane_x;
// 	m->game.plane_x = m->game.plane_x * cos(-rotate_speed) - m->game.plane_y * sin(-rotate_speed);
// 	m->game.plane_y = old_plane * sin(-rotate_speed) + m->game.plane_y * cos(-rotate_speed);
// 	return (1);
// }

// int	rotate_left(t_master *m)
// {
// 	float 	rotate_speed;

// 	rotate_speed = 0.1;
// 	m = 0;
// 	return (0);
// }

int	move_rigth(t_master *m)
{
	float	speed;
	double	posx;
	double	posy;

	speed = 0.1;
	posx = m->game.pos_x;
	posy = m->game.pos_y;
	if (m->move.right == 1)
	{
		if (m->input.mapsplit[(int)(m->game.pos_y + (m->game.dir_y * speed))]
		[(int)(m->game.pos_x + (m->game.dir_x * speed))] == 48)
		{
			m->game.pos_x -= m->game.dir_y * speed;
			m->game.pos_y -= m->game.dir_x * speed;
			if (m->input.mapsplit[(int)(m->game.pos_y + (m->game.dir_y *
			speed))][(int)(m->game.pos_x + (m->game.dir_x * speed))] != 48)
			{
				m->game.pos_x = posx;
				m->game.pos_y = posy;
				return (0);
			}
			return (1);
		}
	}
	return (0);
}

int	move_left(t_master *m)
{
	float	speed;
	double	posx;
	double	posy;

	speed = 0.1;
	posx = m->game.pos_x;
	posy = m->game.pos_y;
	if (m->move.left == 1)
	{
		if (m->input.mapsplit[(int)(m->game.pos_y + (m->game.dir_y * speed))]
		[(int)(m->game.pos_x + (m->game.dir_x * speed))] == '0')
		{
			m->game.pos_x += m->game.dir_y * speed;
			m->game.pos_y += m->game.dir_x * speed;
			if (m->input.mapsplit[(int)(m->game.pos_y + (m->game.dir_y *
			speed))][(int)(m->game.pos_x + (m->game.dir_x * speed))] != 48)
			{
				m->game.pos_x = posx;
				m->game.pos_y = posy;
				return (0);
			}
			return (1);
		}
	}
	return (0);
}

int	move_up(t_master *m)
{
	float	speed;
	double	posx;
	double	posy;

	speed = 0.2;
	posx = m->game.pos_x;
	posy = m->game.pos_y;
	if (m->move.up == 1)
	{
		if (m->input.mapsplit[(int)(m->game.pos_y + (m->game.dir_y * speed))]
		[(int)(m->game.pos_x + (m->game.dir_x * speed))] == 48)
		{
			m->game.pos_x += m->game.dir_x * speed;
			m->game.pos_y += m->game.dir_y * speed;
			if (m->input.mapsplit[(int)(m->game.pos_y + (m->game.dir_y *
			speed))][(int)(m->game.pos_x + (m->game.dir_x * speed))] != 48)
			{
				m->game.pos_x = posx;
				m->game.pos_y = posy;
				return (0);
			}
			return (1);
		}
	}
	return (0);
}

int	move_down(t_master *m)
{
	float	speed;
	double	posx;
	double	posy;

	speed = 0.1;
	posx = m->game.pos_x;
	posy = m->game.pos_y;
	if (m->move.down == 1)
	{
		if (m->input.mapsplit[(int)(m->game.pos_y + (m->game.dir_y * speed))]
		[(int)(m->game.pos_x + (m->game.dir_x * speed))] == 48)
		{
			m->game.pos_x -= m->game.dir_x * speed;
			m->game.pos_y -= m->game.dir_y * speed;
			if (m->input.mapsplit[(int)(m->game.pos_y + (m->game.dir_y *
			speed))][(int)(m->game.pos_x + (m->game.dir_x * speed))] != 48)
			{
				m->game.pos_x = posx;
				m->game.pos_y = posy;
				return (0);
			}
			return (1);
		}
	}
	return (0);
}
