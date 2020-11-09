/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_colors.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 10:58:51 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/09 18:51:01 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void		ft_draw(t_master *m, int x)
{
	int	start;

	start = 0;
	m->game.line_height = (int)(m->game.sh / m->game.perpwalldist);
	m->game.draw_start = -m->game.line_height / 2 + m->game.sh / 2;
	if (m->game.draw_start < 0)
		m->game.draw_start = 0;
	m->game.draw_end = m->game.line_height / 2 + m->game.sh / 2;
	if (m->game.draw_end >= m->game.sh)
		m->game.draw_end = m->game.sh - 1;
	mlx_clear_window(m->vars.mlx, m->vars.win);
	while (start < m->game.draw_start)
	{
		my_mlx_pixel_put(&m->vars, x, start, m->game.ceilingcolor);
		start++;
	}
	ft_texturing(m, x);
	while (m->game.draw_start < m->game.sh)
	{
		my_mlx_pixel_put(&m->vars, x, m->game.draw_start, m->game.floorcolor);
		m->game.draw_start++;
	}
	mlx_put_image_to_window(m->vars.mlx, m->vars.win, m->vars.img, 0, 0);
}
