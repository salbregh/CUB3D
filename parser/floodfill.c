/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floodfill.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/14 14:00:24 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/29 21:11:56 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	ft_check_x(char **map, int x, int y, t_master *m)
{
	if (y == 0 || x == 0)
		ft_error(m, "0 not surrounded");
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'x')
		ft_error(m, "0 not surrounded.");
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'x')
		ft_error(m, "0 not surrounded.");
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'x')
		ft_error(m, "0 not surrounded.");
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'x')
		ft_error(m, "0 not surrounded.");
	if (map[y + 1][x + 1] != '1' && map[y + 1][x + 1] != 'x')
		ft_error(m, "0 not surrounded.");
	if (map[y + 1][x - 1] != '1' && map[y + 1][x - 1] != 'x')
		ft_error(m, "0 not surrounded.");
	if (map[y - 1][x + 1] != '1' && map[y - 1][x + 1] != 'x')
		ft_error(m, "0 not surrounded.");
	if (map[y - 1][x - 1] != '1' && map[y - 1][x - 1] != 'x')
		ft_error(m, "0 not surrounded.");
}

static void	ft_check_map(char **map, t_master *m)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'x')
				ft_check_x(map, x, y, m);
			x++;
		}
		x = 0;
		y++;
	}
}

static char	**ft_floodfill(char **map, int x, int y, t_master *m)
{
	int		i;

	i = 0;
	if (x >= 0 && y >= 0 && y < 13 && map[y][x] &&
		(map[y][x] == '0' || map[y][x] == '2' || map[y][x] == 'N' ||
		map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'W'))
	{
		map[y][x] = 'x';
		ft_floodfill(map, x + 1, y, m);
		ft_floodfill(map, x - 1, y, m);
		ft_floodfill(map, x, y + 1, m);
		ft_floodfill(map, x, y - 1, m);
		ft_floodfill(map, x + 1, y + 1, m);
		ft_floodfill(map, x + 1, y - 1, m);
		ft_floodfill(map, x - 1, y + 1, m);
		ft_floodfill(map, x - 1, y - 1, m);
	}
	return (map);
}

void		ft_validate_map(t_master *m)
{
	int		i;

	m->input.x = ft_split(m->input.map, '\n');
	m->input.x[(int)(m->game.pos_y - 0.5)][(int)(m->game.pos_x - 0.5)] = '0';
	ft_set_sprites(m, 0, 0);
	m->input.x = ft_floodfill(m->input.x, m->game.pos_x, m->game.pos_y, m);
	ft_check_map(m->input.x, m);
	i = 0;
	while (i < m->input.maplines)
	{
		free(m->input.x[i]);
		i++;
	}
	free(m->input.x);
}
