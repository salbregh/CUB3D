/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_struct.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/20 13:18:50 by salbregh      #+#    #+#                 */
/*   Updated: 2020/10/21 10:53:06 by salbregh      ########   odam.nl         */
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
	input->floor = NULL;
	input->resolution = NULL;
	input->map = ft_strdup("");
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
	// m->game.sh = 0;
	// m->game.sw = 0;
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
	vars->bits_per_pixel = 0;
	vars->line_length = 0;
	vars->endian = 0;
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