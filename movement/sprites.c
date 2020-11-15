/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 16:48:07 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/15 17:40:21 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void		ft_set_sprites(t_master *m, int y, int x)
{
	m->sprite.sprite[m->sprite.numberofsprites][0] = x;
	m->sprite.sprite[m->sprite.numberofsprites][1] = y;
	m->sprite.numberofsprites++;
	printf("number of sprites: %d\n", m->sprite.numberofsprites);
	//x en y + 0.5 in struct?
	printf("x: %d\ny: %d\n", x, y);
}

void		ft_sprites(t_master *m, int x)
{
	(void)m;
	(void)x; // x niet nodig?
}
