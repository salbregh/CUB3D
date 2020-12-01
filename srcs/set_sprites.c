/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_sprites.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 10:40:51 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/30 19:42:34 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void		set_array(t_master *m)
{
	int		i;

	i = 0;
	m->sprite.sprite = (double**)malloc(sizeof(double*) * (m->sprite.numb));
	if (m->sprite.sprite == NULL)
		ft_error(m, "Problem with the sprites.");
	while (i < m->sprite.numb)
	{
		m->sprite.sprite[i] = (double *)malloc(sizeof(double) * 2);
		i++;
	}
}

void		ft_set_sprites(t_master *m, int x, int y)
{
	int		i;

	set_array(m);
	i = 0;
	while (y < m->input.maplines)
	{
		while (m->input.mapsplit[y][x] != '\0')
		{
			if (m->input.mapsplit[y][x] == '2')
			{
				m->sprite.sprite[i][0] = x + 0.5;
				m->sprite.sprite[i][1] = y + 0.5;
				m->input.mapsplit[y][x] = '0';
				i++;
			}
			x++;
		}
		y++;
		x = 0;
	}
}

void		ft_draw_sprites(t_master *m)
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
