/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_pictures.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 16:45:53 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/15 14:50:59 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void		ft_load_sprite(t_master *m, int fd)
{
	fd = open(m->input.sprite, O_RDONLY);
	if (fd == -1)
		ft_error(m, "cant open sprite.");
	m->sprite.spr = mlx_png_file_to_image(m->vars.mlx, m->input.sprite, &m->sprite.w_spr, &m->sprite.h_spr);
	m->sprite.addr_spr = mlx_get_data_addr(m->sprite.spr, &m->sprite.bpp_spr, &m->sprite.ll_spr, &m->vars.endian);
	// printf("bpp_spr: %d\nll_spr: %d\nh_spr: %d\nw_spr: %d\n", m->vars.bpp_spr, m->vars.ll_spr, m->vars.h_spr, m->vars.w_spr);
	close(fd);
}

static void		ft_no_so_texture(t_master *m, int fd)
{
	fd = open(m->input.no, O_RDONLY);
	if (fd == -1)
		ft_error(m, "cant open north texture.");
	m->vars.tex_no = mlx_png_file_to_image(m->vars.mlx, m->input.no, &m->vars.w_no, &m->vars.h_no);
	m->vars.addr_no = mlx_get_data_addr(m->vars.tex_no, &m->vars.bpp_no, &m->vars.ll_no, &m->vars.endian);
	close(fd);
	fd = open(m->input.so, O_RDONLY);
	if (fd == -1)
		ft_error(m, "cant open south texture.");
	m->vars.tex_so = mlx_png_file_to_image(m->vars.mlx, m->input.so, &m->vars.w_so, &m->vars.h_so);
	m->vars.addr_so = mlx_get_data_addr(m->vars.tex_so, &m->vars.bpp_so, &m->vars.ll_so, &m->vars.endian);
	close(fd);
}

static void		ft_ea_we_texture(t_master *m, int fd)
{
	fd = open(m->input.ea, O_RDONLY);
	if (fd == -1 )
		ft_error(m, "cant open east texture.");
	m->vars.tex_ea = mlx_png_file_to_image(m->vars.mlx, m->input.ea, &m->vars.w_ea, &m->vars.h_ea);
	m->vars.addr_ea = mlx_get_data_addr(m->vars.tex_ea, &m->vars.bpp_ea, &m->vars.ll_ea, &m->vars.endian);
	close(fd);
	fd = open(m->input.we, O_RDONLY);
	if (fd == -1)
		ft_error(m, "cant open west texture.");
	m->vars.tex_we = mlx_png_file_to_image(m->vars.mlx,m->input.we, &m->vars.w_we, &m->vars.h_we);
	m->vars.addr_we = mlx_get_data_addr(m->vars.tex_we, &m->vars.bpp_we, &m->vars.ll_we, &m->vars.endian);
	close(fd);
}

int				ft_load_pictures(t_master *m)
{
	int fd;

	fd = 0;
	ft_no_so_texture(m, fd);
	ft_ea_we_texture(m, fd);
	ft_load_sprite(m, fd);
	m->vars.img = mlx_new_image(m->vars.mlx, m->game.sw, m->game.sh);
	m->vars.addr = mlx_get_data_addr(m->vars.img, &m->vars.bpp, &m->vars.ll, &m->vars.endian);
	return (0);
}