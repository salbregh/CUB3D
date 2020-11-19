/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_start_raycasting.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/25 18:11:54 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/19 16:11:10 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/*
**	Declare / calculate begin values
**	ray x starts at the players position
**	camera x is the x-coordinate on the camera plane that is the current
**	x-coordinate of the sreen represent (center = 0, right = 1, left = -1)
**	with this the direction vector of the ray can be calculated
**	map x and y represent in which box of the map we're in
**	deltafist x and y are the distance th ray has to travel to go from
**	1 x/y-side to the next x/y-side
*/

static void	ft_start_values(t_master *m, int x)
{
	m->game.camera_x = (2 * x) / (double)m->game.sw - 1;
	m->game.raydir_x = m->game.dir_x + m->game.plane_x * m->game.camera_x;
	m->game.raydir_y = m->game.dir_y + m->game.plane_y * m->game.camera_x;
	m->game.map_x = (int)m->game.pos_x;
	m->game.map_y = (int)m->game.pos_y;
	m->game.deltadist_x = fabs(1 / m->game.raydir_x);
	m->game.deltadist_y = fabs(1 / m->game.raydir_y);
}

/*
**	calculate the step and initialize sidedist
**	sidedist X and Y are the distance the ray has to travel from
**	its start position to the first x-side and the fist y-side
*/

static void	ft_sidedist(t_master *m)
{
	if (m->game.raydir_x < 0)
	{
		m->game.step_x = -1;
		m->game.sidedist_x = (m->game.pos_x - m->game.map_x)
		* m->game.deltadist_x;
	}
	else
	{
		m->game.step_x = 1;
		m->game.sidedist_x = (m->game.map_x + 1.0 - m->game.pos_x)
		* m->game.deltadist_x;
	}
	if (m->game.raydir_y < 0)
	{
		m->game.step_y = -1;
		m->game.sidedist_y = (m->game.pos_y - m->game.map_y)
		* m->game.deltadist_y;
	}
	else
	{
		m->game.step_y = 1;
		m->game.sidedist_y = (m->game.map_y + 1.0 - m->game.pos_y)
		* m->game.deltadist_y;
	}
}

/*
**	performing DDA
**	jump to next map square in x or y direction
*/

static void	ft_dda(t_master *m)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (m->game.sidedist_x < m->game.sidedist_y)
		{
			m->game.sidedist_x += m->game.deltadist_x;
			m->game.map_x += m->game.step_x;
			m->game.side = 0;
		}
		else
		{
			m->game.sidedist_y += m->game.deltadist_y;
			m->game.map_y += m->game.step_y;
			m->game.side = 1;
		}
		if (m->input.mapsplit[m->game.map_y][m->game.map_x] != '0')
			hit = 1;
	}
}

/*
**	calculating the distance projected on camera direction
**	calculate the height of the line to draw on the screen
**	also calculate lowest and highest pixel to fill in current stripe
*/

static void	ft_distance(t_master *m, int x)
{
	if (m->game.side == 0)
	{
		if (m->game.raydir_x == 0)
			m->game.perpwalldist = 0;
		else
			m->game.perpwalldist = ((m->game.map_x - m->game.pos_x +
			(1.0 - m->game.step_x) / 2.0) / m->game.raydir_x);
	}
	else
	{
		if (m->game.raydir_y == 0)
			m->game.perpwalldist = 0;
		else
			m->game.perpwalldist = (m->game.map_y - m->game.pos_y +
			(1.0 - m->game.step_y) / 2.0) / m->game.raydir_y;
	}
	m->sprite.perparray[x - 1] = m->game.perpwalldist;
}

/*
**	calculation for every x on the screen
**	to draw each pixel
*/

void		ft_start_raycasting(t_master *m)
{
	int		x;

	x = 1;
	ft_load_pictures(m);
	while (x < m->game.sw)
	{
		ft_start_values(m, x);
		ft_sidedist(m);
		ft_dda(m);
		ft_distance(m, x);
		ft_draw(m, x);
		x++;
	}
	ft_sprites(m);
	if (m->input.save == 1)
		return (ft_save(m));
}
