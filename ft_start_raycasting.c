/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_start_raycasting.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/25 18:11:54 by salbregh      #+#    #+#                 */
/*   Updated: 2020/10/21 11:15:31 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void		ft_start_raycasting(t_master *m)
{
	int		hit;
	int		x;
	int		w;
	int		h;

	x = 0;
	w = 500;
	h = 500;
	while (x < w)
	{
		// this is the x-coordinate in camera space
		m->game.camera_x = (2 * x) / (double)w - 1;
		// calculate the direction of the ray, for the x and y coordinate of the vector
		m->game.raydir_x = m->game.dir_x + m->game.plane_x * m->game.camera_x;
		m->game.raydir_y = m->game.dir_y + m->game.plane_y * m->game.camera_x;
		// which box of the map we are in
		m->game.map_x = (int)m->game.pos_x;
		m->game.map_y = (int)m->game.pos_y;
		// // length of ray from one x or y side to the next x or y side
		m->game.deltadist_x = fabs(1 / m->game.raydir_x);
		m->game.deltadist_y = fabs(1 / m->game.raydir_y);

		// TRY TO FIX INF
		// if (m->game.raydir_y == 0)
		// 	m->game.deltadist_x = 0;
		// else
		// 	m->game.deltadist_x = fabs(1 / m->game.raydir_x);
		// if (m->game.raydir_x == 0)
		// 	m->game.deltadist_y = 0;
		// else
		// 	m->game.deltadist_x = fabs(1 / m->game.raydir_y);

		// calculate the step and initialize sideDist
		if (m->game.raydir_x < 0)
		{
			m->game.step_x = -1;
			m->game.sidedist_x = (m->game.pos_x - m->game.map_x) * m->game.deltadist_x;
		}
		else
		{
			m->game.step_x = 1;
			m->game.sidedist_x = (m->game.map_x + 1.0 - m->game.pos_x) * m->game.deltadist_x;
		}
		if (m->game.raydir_y < 0)
		{
			m->game.step_y = -1;
			m->game.sidedist_y = (m->game.pos_y - m->game.map_y) * m->game.deltadist_y;
		}
		else
		{
			m->game.step_y = 1;
			m->game.sidedist_y = (m->game.map_y + 1.0 - m->game.pos_y) * m->game.deltadist_y;
		}
		// perform DDA
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
		// calculate the disctance projected on camera direction
		if (m->game.side == 0)
		{
			if (m->game.raydir_x == 0)
				m->game.perpwalldist = 0;
			else
				m->game.perpwalldist = ((m->game.map_x - m->game.pos_x + (1.0 - m->game.step_x) / 2.0) / m->game.raydir_x);
		}
		else
		{
			if (m->game.raydir_y == 0)
				m->game.perpwalldist = 0;
			else
				m->game.perpwalldist = (m->game.map_y - m->game.pos_y + (1.0 - m->game.step_y) / 2.0) / m->game.raydir_y;
		}

		// calculate the height of the line to draw on the screen
		// also calculate lowest and highest pixel to fill in current stripe
		int		line_height;
		int		draw_start;
		int		draw_end;

		line_height = (int)(h / m->game.perpwalldist);
		printf("value lineheight: %i\n", line_height);
		draw_start = -line_height / 2 + h / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + h / 2;
		if (draw_end >= h)
			draw_end = h - 1;
		// colors CHANGE THIS
		unsigned int	color;
		if (m->input.mapsplit[m->game.map_y][m->game.map_x] == '0')
			color = 0x00000000;
		if (m->input.mapsplit[m->game.map_y][m->game.map_x] == '1')
			color = 0x0FFF00FF;
		if (m->input.mapsplit[m->game.map_y][m->game.map_x] == '2')
			color = 0x00FF000F;
		if (m->game.side == 1)
			color = color / 2;
		mlx_clear_window(m->vars.mlx, m->vars.win);
		int a = 0;
		while (a < draw_start) // change
		{
			my_mlx_pixel_put(&m->vars, x, a, 0x00000000);
			a++;
		}
		while (draw_start <= draw_end)
		{
			my_mlx_pixel_put(&m->vars, x, draw_start, color / 1.5);
			draw_start++;
		}
		int b = draw_start;
		while (b < h) // change
		{
			my_mlx_pixel_put(&m->vars, x, b, 0x00000000);
			b++;
		}
		mlx_new_image(m->vars.mlx, 500, 500);
		mlx_put_image_to_window(m->vars.mlx, m->vars.win, m->vars.img, 0, 0);
		x++;
	}
}
