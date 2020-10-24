/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_start_raycasting.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/25 18:11:54 by salbregh      #+#    #+#                 */
/*   Updated: 2020/10/24 18:17:53 by salbregh      ########   odam.nl         */
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
*/

static void	ft_DDA(t_master *m)
{
	int	hit;
	
	hit = 0;
	while (hit == 0)
	{
		// jump to next map square in x or y direction
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
*/

static void	ft_direction(t_master *m)
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
}

/*
**	calculation for every x on the screen
**	to draw each pixel
*/

void		ft_start_raycasting(t_master *m)
{
	// int		hit;
	int		x;

	x = 0;
	while (x < m->game.sw)
	{
		ft_start_values(m, x);
		ft_sidedist(m);
		ft_DDA(m);
		ft_direction(m);

		// calculate the height of the line to draw on the screen
		// also calculate lowest and highest pixel to fill in current stripe
		// int		line_height;
		int		draw_start;
		int		draw_end;

		m->game.line_height = (int)(m->game.sh / m->game.perpwalldist);
		// printf("value lineheight: %i\n", line_height);
		draw_start = -m->game.line_height / 2 + m->game.sh / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = m->game.line_height / 2 + m->game.sh / 2;
		if (draw_end >= m->game.sh)
			draw_end = m->game.sh - 1;
		// colors CHANGE THIS
		unsigned int	color;
		if (m->input.mapsplit[m->game.map_y][m->game.map_x] == '0') // open ruimte?
			color = 0x0F000000;
		if (m->input.mapsplit[m->game.map_y][m->game.map_x] == '1') // muur dus ook textures
			color = 0x0FFF00FF;
		if (m->input.mapsplit[m->game.map_y][m->game.map_x] == '2') // moet sprite worden
			color = 0x00FF000F;
		if (m->game.side == 1)
			color = color / 2;
		mlx_clear_window(m->vars.mlx, m->vars.win);
		int a = 0;
		while (a < draw_start) // change
		{
			my_mlx_pixel_put(&m->vars, x, a, m->game.ceilingcolor);
			a++;
		}
		while (draw_start <= draw_end) // dit wordt texture
		{
			my_mlx_pixel_put(&m->vars, x, draw_start, color / 1.5);
			draw_start++;
		}
		int b = draw_start;
		while (b < m->game.sh) // change
		{
			my_mlx_pixel_put(&m->vars, x, b, m->game.floorcolor);
			b++;
		}
		mlx_new_image(m->vars.mlx, m->game.sw, m->game.sh);
		mlx_put_image_to_window(m->vars.mlx, m->vars.win, m->vars.img, 0, 0);
		x++;
	}
}
