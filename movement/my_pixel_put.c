/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   my_pixel_put.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/25 17:39:12 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/03 17:56:45 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_my_pixel_get(t_master *m, int y, int x)
{
	char	*dst;

	dst = NULL;
	dst = m->vars.addr1 + (x * m->vars.ll1 + y * (m->vars.bpp1 / 8));
	m->vars.color = *(unsigned int *)dst;
}

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = NULL;
	dst = vars->addr + (y * vars->ll + x * (vars->bpp / 8));
	*(unsigned int*)dst = color;
}
