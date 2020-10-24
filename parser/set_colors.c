/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_colors.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/24 12:18:17 by salbregh      #+#    #+#                 */
/*   Updated: 2020/10/24 17:10:21 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

// set colors of floor and ceiling and draw them
// send the draw part from raycasting to these functions

// makes the hex color value
static unsigned int    create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int						ft_set_colors(t_master *m)
{
	printf("input floor color:\nf0: %i\nf1: %i\nf2: %i\n", m->input.f[0], m->input.f[1], m->input.f[2]);
	printf("input ceiling color:\nf0: %i\nf1: %i\nf2: %i\n", m->input.c[0], m->input.c[1], m->input.c[2]);
	m->game.floorcolor = create_trgb(0, m->input.f[0], m->input.f[1], m->input.f[2]);
	printf("input floorcolor: %d\n", m->game.floorcolor);
	m->game.ceilingcolor = create_trgb(0, m->input.c[0], m->input.c[1], m->input.c[2]);
	printf("input ceilingcolor: %d\n", m->game.ceilingcolor);
	return (0);
}


// mys->ceilingcolor = create_trgb(0, mys->c[0], mys->c[1], mys->c[2]);
// mys->floorcolor = create_trgb(0, mys->f[0], mys->f[1], mys->f[2]);