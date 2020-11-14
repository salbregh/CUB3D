/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_colors.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/24 12:18:17 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/13 17:08:28 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/*
** set colors of floor and ceiling and draw them
** send the draw part from raycasting to these functions
** makes the hex color value
*/

static unsigned int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void					ft_set_colors(t_master *m)
{
	m->game.floorcolor =
	create_trgb(0, m->input.f[0], m->input.f[1], m->input.f[2]);
	m->game.ceilingcolor =
	create_trgb(0, m->input.c[0], m->input.c[1], m->input.c[2]);
}
