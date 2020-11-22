/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 16:48:07 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/22 15:41:04 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	ft_set_distance(t_master *m, int i)
{
	m->sprite.distance = (double *)malloc((sizeof(double) * m->sprite.numb));
	while (i < m->sprite.numb)
	{
		m->sprite.distance[i] = ((m->game.pos_x - m->sprite.sprite[i][0]) *
		(m->game.pos_x - m->sprite.sprite[i][0]) + (m->game.pos_y -
		m->sprite.sprite[i][1]) * (m->game.pos_y - m->sprite.sprite[i][1]));
		i++;
	}
}

static void	ft_set_tmp(t_master *m, int j, int i)
{
	int		tmp;
	double	tmpx;
	double	tmpy;

	tmp = m->sprite.distance[j + i];
	tmpx = m->sprite.sprite[j + i][0];
	tmpy = m->sprite.sprite[j + i][1];
	m->sprite.distance[j + i] = m->sprite.distance[i];
	m->sprite.sprite[j + i][0] = m->sprite.sprite[i][0];
	m->sprite.sprite[j + i][1] = m->sprite.sprite[i][1];
	m->sprite.distance[i] = tmp;
	m->sprite.sprite[i][0] = tmpx;
	m->sprite.sprite[i][1] = tmpy;
}

void		ft_sort_sprites(t_master *m, int i, int j)
{
	ft_set_distance(m, i);
	i = 0;
	while (i < m->sprite.numb - 1)
	{
		while (j + i < m->sprite.numb)
		{
			if (m->sprite.distance[j + i] > m->sprite.distance[i])
				ft_set_tmp(m, j, i);
			j++;
		}
		j = 1;
		i++;
	}
	free(m->sprite.distance);
}

static void	ft_start_value(t_master *m, int i)
{
	m->sprite.sprite_x = m->sprite.sprite[i][0] - m->game.pos_x;
	m->sprite.sprite_y = m->sprite.sprite[i][1] - m->game.pos_y;
	m->sprite.inverse = 1.0 / (m->game.plane_x * m->game.dir_y -
	m->game.dir_x * m->game.plane_y);
	m->sprite.trans_x = m->sprite.inverse * (m->game.dir_y *
	m->sprite.sprite_x - m->game.dir_x * m->sprite.sprite_y);
	m->sprite.trans_y = m->sprite.inverse * (-m->game.plane_y *
	m->sprite.sprite_x + m->game.plane_x * m->sprite.sprite_y);
	m->sprite.screen_x = (int)((m->game.sw / 2) *
	(1 + m->sprite.trans_x / m->sprite.trans_y));
	m->sprite.height = fabs(m->game.sh / m->sprite.trans_y);
	m->sprite.drawstart_y = -m->sprite.height / 2 + m->game.sh / 2;
	if (m->sprite.drawstart_y < 0)
		m->sprite.drawstart_y = 0;
	m->sprite.drawend_y = m->sprite.height / 2 + m->game.sh / 2;
	if (m->sprite.drawend_y >= m->game.sh)
		m->sprite.drawend_y = m->game.sh - 1;
	m->sprite.width = fabs(m->game.sh / m->sprite.trans_y);
	m->sprite.drawstart_x = -m->sprite.width / 2 + m->sprite.screen_x;
	if (m->sprite.drawstart_x < 0)
		m->sprite.drawstart_x = 0;
	m->sprite.drawend_x = m->sprite.width / 2 + m->sprite.screen_x;
	if (m->sprite.drawend_x >= m->game.sw)
		m->sprite.drawend_x = m->game.sw - 1;
}

static void	ft_draw_sprites(t_master *m)
{
	int		y;
	int		d;

	m->sprite.tex_x = (int)(256 * (m->sprite.drawstart_x - (-m->sprite.width / 2
	+ m->sprite.screen_x)) * m->sprite.w_spr / m->sprite.width) / 256;
	if (m->sprite.trans_y > 0 && m->sprite.drawstart_x > 0 &&
		m->sprite.drawstart_x < m->game.sw
		&& m->sprite.trans_y < m->sprite.perparray[m->sprite.drawstart_x])
	{
		y = m->sprite.drawstart_y;
		while (y < m->sprite.drawend_y)
		{
			d = y * 256 - m->game.sh * 128 + m->sprite.height * 128;
			m->sprite.tex_y = ((d * m->sprite.h_spr) / m->sprite.height) / 256;
			ft_my_spritepixel_get(m, m->sprite.tex_y, m->sprite.tex_x);
			if (m->sprite.color != 0)
				my_mlx_pixel_put(&m->vars, m->sprite.drawstart_x, y,
				m->sprite.color);
			y++;
		}
	}
	m->sprite.drawstart_x++;
}

void		ft_sprites(t_master *m)
{
	int		i;

	ft_sort_sprites(m, 0, 1);
	i = 0;
	while (i < m->sprite.numb)
	{
		ft_start_value(m, i);
		while (m->sprite.drawstart_x < m->sprite.drawend_x)
			ft_draw_sprites(m);
		i++;
	}
}
