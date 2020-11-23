/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 21:52:03 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/23 13:51:17 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void		ft_error(t_master *m, char *message)
{
	ft_putstr_fd("Error: ", 1);
	ft_putstr_fd(message, 1);
	ft_sort_master(m, 1);
	system("leaks cub3D");
	exit(0);
}
