/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_struct.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 13:11:43 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/30 19:24:08 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	ft_null_more_game(t_game *game)
{
	game->sidedist_x = 0;
	game->sidedist_y = 0;
	game->deltadist_x = 0;
	game->deltadist_y = 0;
	game->perpwalldist = 0;
	game->step_x = 0;
	game->step_y = 0;
	game->side = 0;
}

void		ft_null_game(t_game *game)
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
	ft_null_more_game(game);
}

static void	ft_null_more_vars(t_vars *vars)
{
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

void		ft_null_vars(t_vars *vars)
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
	ft_null_more_vars(vars);
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
