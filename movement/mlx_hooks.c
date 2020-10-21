/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_hooks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/21 12:48:51 by salbregh      #+#    #+#                 */
/*   Updated: 2020/10/21 13:35:47 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	move_bitch(t_master *m)
{
	if (move_up(m) == 1 || move_down(m) == 1 ||
		move_rigth(m) == 1 || move_left(m) == 1)
	{
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
