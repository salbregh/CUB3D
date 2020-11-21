/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_sprites.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 10:40:51 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/21 22:40:57 by salbregh      ########   odam.nl         */
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
