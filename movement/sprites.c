/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 16:48:07 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/16 14:29:09 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void		ft_set_sprites(t_master *m, int x, int y)
{
	int i;
	i = 0;
	// printf("number of sprites: %d\n", m->sprite.numbsprite);
	m->sprite.check = (double **)malloc(sizeof(double *) * (m->sprite.numbsprite + 1));
	while (i < m->sprite.numbsprite)
	{
		m->sprite.check[i] = (double *)malloc((sizeof(double) * 2) + 1);
		i++;
	}
	m->sprite.check[i] = NULL;
	i = 0;
	while (y < m->input.maplines)
	{
		while (m->input.mapsplit[y][x] != '\0')
		{
			if (m->input.mapsplit[y][x] == '2')
			{
				printf("2 found\n");
				m->sprite.check[i][0] = x + 0.5;
				printf("m->sprite.check[i][0] = %f\n", m->sprite.check[i][0]);
				m->sprite.check[i][1] = y + 0.5;
				printf("m->sprite.check[i][1] = %f\n", m->sprite.check[i][1]);
				m->sprite.check[i][2] = '\0';
				m->input.mapsplit[y][x] = '0';
				i++;
			}
			x++;
		}
		y++;
		x = 0;
	}
	i = 0;
	while (i < m->sprite.numbsprite)
	{
		printf("i: %d\n", i);
		printf("value of x: %f\t", m->sprite.check[i][0]);
		printf("value of y: %f\n", m->sprite.check[i][1]);
		i++;
	}
}

void		ft_sprites(t_master *m)
{
	int		i;

	i = 0;
	m->sprite.sprite = (double **)malloc(sizeof(double *) * (m->sprite.numbsprite + 1));
	while (i < m->sprite.numbsprite)
	{
		m->sprite.sprite[i] = (double *)malloc((sizeof(double) * 2) + 1);
		i++;
	}
	m->sprite.sprite = m->sprite.check;
	m->sprite.spritedistance = (double *)malloc((sizeof(double) * m->sprite.numbsprite) + 1);
	i = 0;
	while (i < m->sprite.numbsprite)
	{
		m->sprite.spritedistance[i] = ((m->game.pos_x - m->sprite.sprite[i][0]) * (m->game.pos_x - m->sprite.sprite[i][0]) + (m->game.pos_y - m->sprite.sprite[i][1]) * (m->game.pos_y - m->sprite.sprite[i][1]));
		printf("distance[%i] = %f\n", i, m->sprite.spritedistance[i]);
		i++;
	}
	// sort the sprites
	i = 0;
	// while (i < m->sprite.numbsprite)
	// {
	// 	printf("DISTANCE %i : %f\n", i, m->sprite.spritedistance[i]);
	// 	i++;
	// }
	// i = 0;
	while (i < m->sprite.numbsprite)
	{
		m->sprite.sprite_x = m->sprite.sprite[i][0] - m->game.pos_x;
		m->sprite.sprite_y = m->sprite.sprite[i][1] - m->game.pos_y;

		m->sprite.inverse = 1.0 / (m->game.plane_x * m->game.dir_y - m->game.dir_x * m->game.plane_y);
		
		m->sprite.trans_x = m->sprite.inverse * (m->game.dir_y * m->sprite.sprite_x - m->game.dir_x * m->sprite.sprite_y);
		m->sprite.trans_y = m->sprite.inverse * (-m->game.plane_y * m->sprite.sprite_x + m->game.plane_x * m->sprite.sprite_y);
		
		m->sprite.screen_x = (int)((m->game.sw / 2) * (1 + m->sprite.trans_x / m->sprite.trans_y));
		
		m->sprite.height  = fabs(m->game.sh / m->sprite.trans_y); // (int)
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

		int		stripe;
		stripe = m->sprite.drawstart_x;
		while (stripe < m->sprite.drawend_x)
		{
			m->sprite.tex_x = (int)(256 * (stripe - (-m->sprite.width / 2 + m->sprite.screen_x)) * m->sprite.w_spr / m->sprite.width) / 256;
			if (m->sprite.trans_y > 0 && stripe > 0 && stripe < m->game.sw && m->sprite.trans_y < m->sprite.perparray[stripe])
			{
				int y = m->sprite.drawstart_y;
				while (y < m->sprite.drawend_y)
				{
					int d = y * 256 - m->game.sh * 128 + m->sprite.height * 128;
					m->sprite.tex_y = ((d * m->sprite.h_spr) / m->sprite.height) / 256;
					ft_my_spritepixel_get(m, m->sprite.tex_y, m->sprite.tex_x);
					if (m->sprite.color != 0)
						my_mlx_pixel_put(&m->vars, stripe, y, m->sprite.color);
					y++;
				}
			}
			stripe++;
		}
		i++;
	}
}
