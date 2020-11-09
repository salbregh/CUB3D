/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 18:18:30 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/09 23:35:13 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

// static void PRINT(t_master *m)
// {
// 	printf("TESTVALUES:\n");
// 	printf("texture1: %s\n", m->vars.texture1);
// 	printf("addr1: %s\n", m->vars.addr1);
// 	printf("w1: %d\n", m->vars.w1);
// 	printf("h1: %d\n", m->vars.h1);
// 	printf("bpp1: %d\n", m->vars.bpp1);
// 	printf("ll1: %d\n", m->vars.ll1);
// 	printf("color: %d\n", m->vars.color);
// 	printf("wall_x: %f\n", m->vars.wall_x);
// 	printf("tex_step: %f\n", m->vars.tex_step);
// 	printf("line_heigth: %d\n", m->vars.line_height);
// 	printf("tex_x: %d\n", m->vars.tex_x);
// 	printf("tex_y: %d\n", m->vars.tex_y);
// 	printf("tex_pos: %d\n", m->vars.tex_pos);
// }

static void	ft_my_pixel_get(t_master *m, int x, int y)
{
	char	*dst;

	// printf("int x: %d\nint y: %d\n", x, y);
	dst = m->vars.addr1 + (x * m->vars.ll1 + y * (m->vars.bpp1 / 8));
	m->vars.color = *(unsigned int *)dst;
	// color of the sprite
	if (m->input.mapsplit[m->game.map_y][m->game.map_x] == '2')
		m->vars.color = 0x00FF000F;
}

// static void	ft_vertical_pixel(int x, int y, t_master *m)
// {
// 	char	*dst;

// 	dst = NULL;
// 	dst = m->vars.addr + (y * m->vars.ll + x *
// 	(m->vars.bpp / 8));
// 	*(unsigned int*)dst = m->vars.color;
// }

void	ft_texturing(t_master *m, int x)
{
	if (m->game.side == 0)
		m->vars.wall_x = m->game.pos_y + m->game.perpwalldist * m->game.raydir_y;
	else
		m->vars.wall_x = m->game.pos_x + m->game.perpwalldist * m->game.raydir_x;
	m->vars.wall_x -= (int)m->vars.wall_x;
	m->vars.tex_y = (int)(m->vars.wall_x * (double)m->vars.w1);
	if (m->game.side == 0 && m->game.raydir_x > 0)
		m->vars.tex_y = m->vars.w1 - m->vars.tex_y - 1;
	if (m->game.side == 0 && m->game.raydir_y < 0)
		m->vars.tex_y = m->vars.w1 - m->vars.tex_y - 1;
	m->vars.tex_step = 1.0 * m->vars.h1 / m->game.line_height;
	m->vars.tex_pos = (m->game.draw_start - m->game.sh / 2 + m->game.line_height / 2) * m->vars.tex_step;
	while (m->game.draw_start < m->game.draw_end)
	{
		// m->vars.tex_step = (double)m->vars.h1 / (double)m->game.line_height;
		// m->vars.tex_pos = ((m->game.draw_start - (m->game.sh / 2) + m->game.line_height / 2) * m->vars.tex_step);
		m->vars.tex_x = (int)m->vars.tex_pos;
		m->vars.tex_pos = m->vars.tex_pos + m->vars.tex_step;
		ft_my_pixel_get(m, m->vars.tex_x, m->vars.tex_y);
		my_mlx_pixel_put(&m->vars, x, m->game.draw_start, m->vars.color);
		// ft_vertical_pixel(x, m->game.draw_start, m);
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
