/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 18:18:30 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/03 22:24:53 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_texturing(t_master *m, int x, unsigned int color)
{
	while (m->game.draw_start < m->game.draw_end)
	{
		my_mlx_pixel_put(&m->vars, x, m->game.draw_start, color / 1.5);
		m->game.draw_start++;
	}
}

int		ft_load_texture(t_master *m)
{
	int fd;
	fd = open(m->input.no, O_RDONLY);
	if (fd == -1)
		ft_error(m, "cant open north texture");
	m->vars.texture1 = mlx_png_file_to_image(m->vars.mlx, m->input.no, &m->vars.w1, &m->vars.h1);
	m->vars.addr1 = mlx_get_data_addr(m->vars.texture1, &m->vars.bpp1, &m->vars.ll1, &m->vars.endian);
	// m->vars.img = mlx_new_image(m->vars.mlx, m->game.sw, m->game.sh);
	// m->vars.addr = mlx_get_data_addr(m->vars.mlx, &m->vars.bpp, &m->vars.ll, &m->vars.endian);
	return (0);
}