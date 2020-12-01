/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_more_struct.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 13:05:22 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/30 19:41:02 by salbregh      ########   odam.nl         */
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

void		ft_null_input(t_input *input)
{
	input->save = 0;
	input->savecolor = 0;
	input->no = NULL;
	input->so = NULL;
	input->ea = NULL;
	input->we = NULL;
	input->sprite = NULL;
	input->ceiling = NULL;
	input->c[0] = 0;
	input->c[1] = 0;
	input->c[2] = 0;
	input->floor = NULL;
	input->f[0] = 0;
	input->f[1] = 0;
	input->f[2] = 0;
	input->res = NULL;
	input->which = 0;
	input->map = ft_strdup("");
	input->maplines = 0;
	input->checkmap = 0;
	input->lineinmap = 0;
	input->mapsplit = NULL;
	input->x = NULL;
}

void		ft_null_move(t_move *move)
{
	move->up = 0;
	move->down = 0;
	move->left = 0;
	move->right = 0;
	move->rotate_left = 0;
	move->rotate_right = 0;
}

void		ft_null_sprite(t_sprite *sprite)
{
	sprite->spr = NULL;
	sprite->addr_spr = NULL;
	sprite->w_spr = 0;
	sprite->h_spr = 0;
	sprite->bpp_spr = 0;
	sprite->ll_spr = 0;
	sprite->numb = 0;
	sprite->perparray = 0;
	sprite->distance = NULL;
	sprite->sprite = NULL;
	sprite->sprite_x = 0;
	sprite->sprite_y = 0;
	sprite->inverse = 0;
	sprite->trans_x = 0;
	sprite->trans_y = 0;
	sprite->screen_x = 0;
	sprite->height = 0;
	sprite->width = 0;
	sprite->drawstart_y = 0;
	sprite->drawend_y = 0;
	sprite->drawstart_x = 0;
	sprite->drawend_x = 0;
	sprite->tex_x = 0;
	sprite->tex_y = 0;
	sprite->color = 0;
}
