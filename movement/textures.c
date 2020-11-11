/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 18:18:30 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/11 16:32:50 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	ft_set_texture(t_master *m)
{
	// verander dit
	if (m->game.side == 1 && m->game.raydir_y >= 0)
	{
		m->vars.tex_ = m->vars.tex_so;
		m->vars.addr_ = m->vars.addr_so;
		m->vars.w_ = m->vars.w_so;
		m->vars.h_ = m->vars.h_so;
		m->vars.bpp_ = m->vars.bpp_so;
		m->vars.ll_ = m->vars.ll_so;
	}
	if (m->game.side == 1 && m->game.raydir_y < 0)
	{
		m->vars.tex_ = m->vars.tex_no;
		m->vars.addr_ = m->vars.addr_no;
		m->vars.w_ = m->vars.w_no;
		m->vars.h_ = m->vars.h_no;
		m->vars.bpp_ = m->vars.bpp_no;
		m->vars.ll_ = m->vars.ll_no;
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
	if (m->game.side == 0 && m->game.raydir_x >= 0)
	{
		m->vars.tex_ = m->vars.tex_ea;
		m->vars.addr_ = m->vars.addr_ea;
		m->vars.w_ = m->vars.w_ea;
		m->vars.h_ = m->vars.h_ea;
		m->vars.bpp_ = m->vars.bpp_ea;
		m->vars.ll_ = m->vars.ll_ea;
	}
}

static void	ft_my_pixel_get(t_master *m, int x, int y)
{
	char	*dst;

	dst = m->vars.addr_ + (x * m->vars.ll_ + y * (m->vars.bpp_ / 8));
	m->vars.color = *(unsigned int *)dst;
	if (m->input.mapsplit[m->game.map_y][m->game.map_x] == '2')
		m->vars.color = 0x00FF000F;
}

void	ft_texturing(t_master *m, int x)
{
	ft_set_texture(m);
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

int		ft_load_texture(t_master *m)
{
	int fd;
	fd = open(m->input.no, O_RDONLY);
	if (fd == -1)
		ft_error(m, "cant open north texture");
	m->vars.tex_no = mlx_png_file_to_image(m->vars.mlx, m->input.no, &m->vars.w_no, &m->vars.h_no);
	m->vars.addr_no = mlx_get_data_addr(m->vars.tex_no, &m->vars.bpp_no, &m->vars.ll_no, &m->vars.endian);
	close(fd);
	fd = open(m->input.so, O_RDONLY);
	if (fd == -1)
		ft_error(m, "cant open south texture");
	m->vars.tex_so = mlx_png_file_to_image(m->vars.mlx, m->input.so, &m->vars.w_so, &m->vars.h_so);
	m->vars.addr_so = mlx_get_data_addr(m->vars.tex_so, &m->vars.bpp_so, &m->vars.ll_so, &m->vars.endian);
	fd = open(m->input.ea, O_RDONLY);
	if (fd == -1 )
		ft_error(m, "cant open east texture");
	m->vars.tex_ea = mlx_png_file_to_image(m->vars.mlx, m->input.ea, &m->vars.w_ea, &m->vars.h_ea);
	m->vars.addr_ea = mlx_get_data_addr(m->vars.tex_ea, &m->vars.bpp_ea, &m->vars.ll_ea, &m->vars.endian);
	close(fd);
	fd = open(m->input.we, O_RDONLY);
	if (fd == -1)
		ft_error(m, "cant open west texture");
	m->vars.tex_we = mlx_png_file_to_image(m->vars.mlx, m->input.we, &m->vars.w_we, &m->vars.h_we);
	m->vars.addr_we = mlx_get_data_addr(m->vars.tex_we, &m->vars.bpp_we, &m->vars.ll_we, &m->vars.endian);
	close(fd);
	m->vars.img = mlx_new_image(m->vars.mlx, m->game.sw, m->game.sh);
	m->vars.addr = mlx_get_data_addr(m->vars.img, &m->vars.bpp, &m->vars.ll, &m->vars.endian);
	return (0);
}
