/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_struct.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 13:11:43 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/22 17:01:00 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_null_input(t_input *input)
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

static void	ft_null_game(t_game *game)
{
	game->pos_y = 0;
	game->pos_x = 0;
	game->pos = 0;
	game->line_height = 0;
	game->sh = 0;
	game->sw = 0;
	game->draw_start = 0;
	game->draw_end = 0;
	game->ceilingcolor = 0;
	game->floorcolor = 0;
	game->dir_x = 0;
	game->dir_y = 0;
	game->plane_x = 0;
	game->plane_y = 0;
	game->camera_x = 0;
	game->raydir_x = 0;
	game->raydir_y = 0;
	game->map_x = 0;
	game->map_y = 0;
	game->sidedist_x = 0;
	game->sidedist_y = 0;
	game->deltadist_x = 0;
	game->deltadist_y = 0;
	game->perpwalldist = 0;
	game->step_x = 0;
	game->step_y = 0;
	game->side = 0;
}

static void	ft_null_move(t_move *move)
{
	move->up = 0;
	move->down = 0;
	move->left = 0;
	move->right = 0;
	move->rotate_left = 0;
	move->rotate_right = 0;
}

static void	ft_null_vars(t_vars *vars)
{
	vars->mlx = NULL;
	vars->win = NULL;
	vars->img = NULL;
	vars->addr = NULL;
	vars->bpp = 0;
	vars->ll = 0;
	vars->endian = 0;
	vars->tex_no = NULL;
	vars->addr_no = NULL;
	vars->w_no = 0;
	vars->h_no = 0;
	vars->bpp_no = 0;
	vars->ll_no = 0;
	vars->tex_so = NULL;
	vars->addr_so = NULL;
	vars->w_so = 0;
	vars->h_so = 0;
	vars->bpp_so = 0;
	vars->ll_so = 0;
	vars->tex_ea = NULL;
	vars->addr_ea = NULL;
	vars->w_ea = 0;
	vars->h_ea = 0;
	vars->bpp_ea = 0;
	vars->ll_ea = 0;
	vars->tex_we = NULL;
	vars->addr_we = NULL;
	vars->w_we = 0;
	vars->h_we = 0;
	vars->bpp_we = 0;
	vars->ll_we = 0;
	vars->tex_ = NULL;
	vars->addr_ = NULL;
	vars->w_ = 0;
	vars->h_ = 0;
	vars->bpp_ = 0;
	vars->ll_ = 0;
	vars->wall_x = 0;
	vars->tex_step = 0;
	vars->color = 0;
	vars->tex_x = 0;
	vars->tex_y = 0;
	vars->tex_pos = 0;
}

static void	ft_null_sprite(t_sprite *sprite)
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

void		ft_sort_master(t_master *m)
{
	t_input		input;
	t_game		game;
	t_move		move;
	t_vars		vars;
	t_sprite	sprite;

	ft_null_input(&input);
	m->input = input;
	ft_null_game(&game);
	m->game = game;
	ft_null_move(&move);
	m->move = move;
	ft_null_vars(&vars);
	m->vars = vars;
	ft_null_sprite(&sprite);
	m->sprite = sprite;
}
