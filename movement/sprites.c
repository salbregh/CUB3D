/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 16:48:07 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/15 21:15:15 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void		ft_set_sprites(t_master *m, int x, int y)
{
	int i;
	i = 0;
	printf("number of sprites: %d\n", m->sprite.numbsprite);
	m->sprite.sprite = (double **)malloc(sizeof(double *) * (m->sprite.numbsprite + 1));
	while (i < m->sprite.numbsprite)
	{
		m->sprite.sprite[i] = (double *)malloc((sizeof(double) * 2) + 1);
		i++;
	}
	m->sprite.sprite[i] = NULL;
	i = 0;
	while (y < m->input.maplines)
	{
		while (m->input.mapsplit[y][x] != '\0')
		{
			if (m->input.mapsplit[y][x] == '2')
			{
				printf("2 found\n");
				m->sprite.sprite[i][0] = x + 0.5;
				printf("m->sprite.sprite[i][0] = %f\n", m->sprite.sprite[i][0]);
				m->sprite.sprite[i][1] = y + 0.5;
				printf("m->sprite.sprite[i][1] = %f\n", m->sprite.sprite[i][1]);
				m->sprite.sprite[i][2] = '\0';
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
		printf("value of x: %f\t", m->sprite.sprite[i][0]);
		printf("value of y: %f\n", m->sprite.sprite[i][1]);
		i++;
	}
}

void		ft_sprites(t_master *m)
{
	int		i;

	i = 0;
	ft_set_sprites(m, 0, 0);
	m->sprite.spriteorder = (int *)malloc((sizeof(int) * m->sprite.numbsprite) + 1);
	m->sprite.spritedistance = (double *)malloc((sizeof(double) * m->sprite.numbsprite) + 1);
	while (i < m->sprite.numbsprite)
	{
		m->sprite.spriteorder[i] = i;
		m->sprite.spritedistance[i] = ((m->game.pos_x - m->sprite.sprite[i][0]) * (m->game.pos_x - m->sprite.sprite[i][0]) + (m->game.pos_y - m->sprite.sprite[i][1]) * (m->game.pos_y - m->sprite.sprite[i][1]));
		i++;
	}
	// sort the sprites
	i = 0;
	while (i < m->sprite.numbsprite)
	{
		printf("DISTANCE %i : %f\n", i, m->sprite.spritedistance[i]);
		i++;
	}
	i = 0;
}
