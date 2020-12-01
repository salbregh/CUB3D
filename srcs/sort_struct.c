/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_struct.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 13:11:43 by salbregh      #+#    #+#                 */
/*   Updated: 2020/12/01 22:22:30 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	ft_free_more(t_master *m)
{
	free(m->sprite.perparray);
	free(m->input.mapsplit);
	free(m->sprite.sprite);
	free(m->input.no);
	free(m->input.so);
	free(m->input.ea);
	free(m->input.we);
	free(m->input.sprite);
	free(m->input.ceiling);
	free(m->input.floor);
	free(m->input.res);
	free(m->input.map);
}

void		ft_free_all(t_master *m)
{
	int		i;

	i = 0;
	if (m->sprite.sprite != NULL)
	{
		while (i < m->sprite.numb)
		{
			free(m->sprite.sprite[i]);
			i++;
		}
	}
	i = 0;
	if (m->input.mapsplit != 0)
	{
		while (i < m->input.maplines)
		{
			free(m->input.mapsplit[i]);
			i++;
		}
	}
	ft_free_more(m);
}

void		ft_sort_master(t_master *m, int free)
{
	t_input		input;
	t_game		game;
	t_move		move;
	t_vars		vars;
	t_sprite	sprite;

	if (free == 1)
		ft_free_all(m);
	ft_memset(&vars, 0, sizeof(t_vars));
	m->vars = vars;
	ft_memset(&game, 0, sizeof(t_game));
	m->game = game;
	ft_memset(&move, 0, sizeof(t_move));
	m->move = move;
	ft_memset(&input, 0, sizeof(t_input));
	input.map = ft_strdup(""); // veranderdit
	m->input = input;
	ft_memset(&sprite, 0, sizeof(t_sprite));
	m->sprite = sprite;
}
