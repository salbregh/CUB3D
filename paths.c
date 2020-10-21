/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   paths.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/04 19:08:20 by salbregh      #+#    #+#                 */
/*   Updated: 2020/07/07 12:28:39 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void		ft_set_north(t_master *m, char *line)
{
	// if (m->input.no != NULL)
	// 	ft_error("ERROR WITH NORTH PATH");
	m->input.no = ft_path_trim(line, "NO");
}

void		ft_set_south(t_master *m, char *line)
{
	// if (m->input.so != NULL)
	// 	ft_error("ERROR WITH SOUTH PATH");
	m->input.so = ft_path_trim(line, "SO");
}

void		ft_set_west(t_master *m, char *line)
{
	// if (m->input.we != NULL)
	// 	ft_error("ERROR WITH WEST PATH");
	m->input.we = ft_path_trim(line, "WE");
}

void		ft_set_east(t_master *m, char *line)
{
	// if (m->input.ea != NULL)
	// 	ft_error("ERROR WITH EAST PATH");
	m->input.ea = ft_path_trim(line, "EA");
}

void		ft_set_sprite(t_master *m, char *line)
{
	// if (m->input.sprite != NULL)
	// 	ft_error("ERROR WITH SPRITE PATH");
	m->input.sprite = ft_path_trim(line, "S ");
}

char		*ft_path_trim(char *line, char *set)
{
	int	i;

	i = 0;
	line = ft_strtrim(line, " ");
	while (line[0] != '.')
	{
		if (*line != ' ')
			line = ft_strtrim(line, set);
		if (*line == ' ')
			line = ft_strtrim(line, " ");
	}
	return (line);
}
