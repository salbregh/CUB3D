/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/30 10:23:10 by salbregh      #+#    #+#                 */
/*   Updated: 2020/10/21 11:42:35 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
		[(int)(m->game.pos_x + (m->game.dir_x * speed))] == 48)
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

	// printf("value move up in move up: %i\n", m->move.up);
	speed = 0.1;
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

int	move_bitch(t_master *m)
{
	if (move_up(m) == 1 || move_down(m) == 1 ||
		move_rigth(m) == 1 || move_left(m) == 1)
	{
		printf("goes in");
		mlx_clear_window(m->vars.mlx, m->vars.win);
		ft_start_raycasting(m);
	}
	return (0);
}

int	close_button(t_master *m)
{
	mlx_clear_window(m->vars.mlx, m->vars.win);
	mlx_destroy_window(m->vars.mlx, m->vars.win);
	exit(0);
}

int	key_release(int keycode, t_master *m)
{
	if (keycode == 13)
		m->move.up = 0;
	if (keycode == 1)
		m->move.down = 0;
	if (keycode == 0)
		m->move.left = 0;
	if (keycode == 2)
		m->move.right = 0;
	if (keycode == 123)
		m->move.rotate_left = 0;
	if (keycode == 124)
		m->move.rotate_right = 0;
	return (0);
}

int	key_press(int keycode, t_master *m)
{
	printf("keycode: %i\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(m->vars.mlx, m->vars.win);
		exit(0);
	}
	if (keycode == 13)
	{
		m->move.up = 1;
		printf("value move up: %i\n", m->move.up);
	}
	if (keycode == 1)
		m->move.down = 1;
	if (keycode == 0)
		m->move.left = 1;
	if (keycode == 2)
		m->move.right = 1;
	if (keycode == 123)
		m->move.rotate_left = 1;
	if (keycode == 124)
		m->move.rotate_right = 1;
	return (0);
}
