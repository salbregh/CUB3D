/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 18:18:30 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/14 17:57:23 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	ft_ea_we_texture(t_master *m)
{
	if (m->game.side == 0 && m->game.raydir_x >= 0)
	{
		m->vars.tex_ = m->vars.tex_ea;
		m->vars.addr_ = m->vars.addr_ea;
		m->vars.w_ = m->vars.w_ea;
		m->vars.h_ = m->vars.h_ea;
		m->vars.bpp_ = m->vars.bpp_ea;
		m->vars.ll_ = m->vars.ll_ea;
	}
	if (m->game.side == 0 && m->game.raydir_x < 0)
	{
		m->vars.tex_ = m->vars.tex_we;
		m->vars.addr_ = m->vars.addr_we;
		m->vars.w_ = m->vars.w_we;
		m->vars.h_ = m->vars.h_we;
		m->vars.bpp_ = m->vars.bpp_we;
		m->vars.ll_ = m->vars.ll_we;
	}	
}

static void	ft_no_so_texture(t_master *m)
{
	if (m->game.side == 1 && m->game.raydir_y < 0)
	{
		m->vars.tex_ = m->vars.tex_no;
		m->vars.addr_ = m->vars.addr_no;
		m->vars.w_ = m->vars.w_no;
		m->vars.h_ = m->vars.h_no;
		m->vars.bpp_ = m->vars.bpp_no;
		m->vars.ll_ = m->vars.ll_no;
	}
	if (m->game.side == 1 && m->game.raydir_y >= 0)
	{
		m->vars.tex_ = m->vars.tex_so;
		m->vars.addr_ = m->vars.addr_so;
		m->vars.w_ = m->vars.w_so;
		m->vars.h_ = m->vars.h_so;
		m->vars.bpp_ = m->vars.bpp_so;
		m->vars.ll_ = m->vars.ll_so;
	}
}

void	ft_texturing(t_master *m, int x)
{
	ft_no_so_texture(m);
	ft_ea_we_texture(m);
	if (m->game.side == 0)
		m->vars.wall_x = m->game.pos_y + m->game.perpwalldist * m->game.raydir_y;
	else
		m->vars.wall_x = m->game.pos_x + m->game.perpwalldist * m->game.raydir_x;
	m->vars.wall_x -= (int)m->vars.wall_x;
	m->vars.tex_y = (int)(m->vars.wall_x * (double)m->vars.w_);
	if (m->game.side == 0 && m->game.raydir_x > 0)
		m->vars.tex_y = m->vars.w_ - m->vars.tex_y - 1;
	if (m->game.side == 0 && m->game.raydir_y < 0)
		m->vars.tex_y = m->vars.w_ - m->vars.tex_y - 1;
	m->vars.tex_step = 1.0 * m->vars.h_ / m->game.line_height;
	m->vars.tex_pos = (m->game.draw_start - m->game.sh / 2 + m->game.line_height / 2) * m->vars.tex_step;
	while (m->game.draw_start < m->game.draw_end)
	{
		m->vars.tex_x = (int)m->vars.tex_pos;
		m->vars.tex_pos = m->vars.tex_pos + m->vars.tex_step;
		ft_my_pixel_get(m, m->vars.tex_x, m->vars.tex_y);
		my_mlx_pixel_put(&m->vars, x, m->game.draw_start, m->vars.color);
		m->game.draw_start++;
	}
}
