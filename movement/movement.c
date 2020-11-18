/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/30 10:23:10 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/18 14:44:02 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int		sprite_check(t_master *m)
{
	int			i;
	int			x;
	int			y;

	// printf("Goes in");
	i = 0;
	// m->input.mapsplit[m->game.map_y][m->game.map_x] 
	while (i < m->sprite.numbsprite)
	{
		x = (int)m->sprite.sprite[i][0];
		y = (int)m->sprite.sprite[i][1];
		printf("sprite y: %d\tpos_y: %d\n", y, (int)m->game.pos_y);
		printf("sprite x: %d\tpos_x: %d\n", x, (int)m->game.pos_x);
		if ((int)m->game.pos_y == y && (int)m->game.pos_x == x)
		{
			printf("it is");
			return (-1);
		}
			
		i++;
	}
	return (0);
}

int		rotate_right(t_master *m)
{
	double	oldDirX;
	double	oldPlaneX;
	double	speed;

	oldDirX = m->game.dir_x;
	oldPlaneX = m->game.plane_x;
	speed = 0.1;
	if (m->move.rotate_right == 1)
	{
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
	if (m->move.rotate_left == 1)
	{
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

	speed = 0.1;
	if (m->move.up == 1)
	{
		if (m->input.mapsplit[(int)(m->game.pos_y + (m->game.dir_y * speed))]
			[(int)(m->game.pos_x + (m->game.dir_x * speed))] == '0' && sprite_check(m) == 0)
		{
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

	speed = 0.1;
	if (m->move.down == 1)
	{
		if (m->input.mapsplit[(int)(m->game.pos_y - (m->game.dir_y * speed))]
			[(int)(m->game.pos_x - (m->game.dir_x * speed))] == '0')// && sprite_check(m) == 0)
		{
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

	speed = 0.1;
	if (m->move.right == 1)
	{
		if (m->input.mapsplit[(int)(m->game.pos_y + (m->game.plane_y * speed))]
		[(int)(m->game.pos_x + (m->game.plane_x * speed))] == '0')
		{
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

	speed = 0.1;
	if (m->move.left == 1)
	{
		if (m->input.mapsplit[(int)(m->game.pos_y - (m->game.plane_y * speed))]
		[(int)(m->game.pos_x - (m->game.plane_x * speed))] == '0')
		{
			m->game.pos_x -= m->game.plane_x * speed;
			m->game.pos_y -= m->game.plane_y * speed;
			return (1);
		}
	}
	return (0);
}
