/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_struct.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/20 13:18:50 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/15 14:57:51 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_null_input(t_input *input)
{
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
	input->resolution = NULL;
	input->which = 0;
	input->map = ft_strdup("");
	input->checkmap = 0;
	input->lineinmap = 0;
	input->mapsplit = NULL;
	input->x = NULL;
	// input->numberofsprites = 0;
}

static void	ft_null_game(t_game *game)
{
	game->x = 1;
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
	// game->perparray = NULL;
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
	// texture variables
	vars->tex_no = 0;
	vars->addr_no = 0;
	vars->w_no = 0;
	vars->h_no = 0;
	vars->bpp_no = 0;
	vars->ll_no = 0;
	// add so ea and we
	vars->wall_x = 0;
	vars->tex_step = 0;
	vars->color = 0;
	vars->tex_x = 0;
	vars->tex_y = 0;
	vars->tex_pos = 0;
}

void		ft_sort_master(t_master *m)
{
	t_input		input;
	t_game		game;
	t_move		move;
	t_vars		vars;

	ft_null_input(&input);
	m->input = input;
	ft_null_game(&game);
	m->game = game;
	ft_null_move(&move);
	m->move = move;
	ft_null_vars(&vars);
	m->vars = vars;
}
