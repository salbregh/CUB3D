/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_sprites.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 10:40:51 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/23 12:00:45 by salbregh      ########   odam.nl         */
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
