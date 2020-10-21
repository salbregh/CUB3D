/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floodfill.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/14 14:00:24 by salbregh      #+#    #+#                 */
/*   Updated: 2020/10/21 09:19:28 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

// delete printstatements
static int	ft_check_x(char **map, int x, int y)
{
	if (map[y][x + 1])
		if (map[y][x + 1] != '1' && (map[y][x + 1]) != 'x')
		{
			printf("0 not surrounded correctly on the right");
			return (-1);
		}
	if (map[y][x - 1])
		if (map[y][x - 1] != '1' && (map[y][x - 1]) != 'x')
		{
			printf("0 not surrounded correctly on the left");
			return (-1);
		}
	if (map[y - 1][x])
		if (map[y - 1][x] != '1' && (map[y - 1][x]) != 'x')
		{
			printf("0 not surrounded correctly on the top");
			return (-1);
		}
	if (map[y + 1][x])
		if (map[y + 1][x] != '1' && (map[y + 1][x]) != 'x')
		{
			printf("0 not surrounded correctly on the bottom");
			return (-1);
		}
	if (map[y + 1][x + 1])
		if (map[y + 1][x + 1] != '1' && map[y + 1][x + 1] != 'x')
		{
			printf("0 not surrounded correctly upright");
			return (-1);
		}
	if (map[y + 1][x - 1])
		if (map[y + 1][x - 1] != '1' && map[y + 1][x - 1] != 'x')
		{
			printf("0 not surrounded correctly upleft");
			return (-1);
		}
	if (map[y - 1][x + 1])
		if (map[y - 1][x + 1] != '1' && map[y - 1][x + 1] != 'x')
		{
			printf("0 not surrounded correctly downright");
			return (-1);
		}
	if (map[y - 1][x - 1])
		if (map[y - 1][x - 1] != '1' && map[y - 1][x - 1] != 'x')
		{
			printf("0 not surrounded correctly downleft");
			return (-1);
		}
	return (0);
}

static int	ft_check_map(char **map)
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
			{
				if (ft_check_x(map, x, y) == -1)
				{
					printf("goes wrong on map[%d][%d] = map y, x\n", y, x);
					return (-1);
				}
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

static char	**ft_floodfill(char **map, int x, int y)
{
	int		i;

	i = 0;
	if ((map[y][x] == '0' || map[y][x] == '2') && map[y][x])
	{
		map[y][x] = 'x';
		ft_floodfill(map, x + 1, y);
		ft_floodfill(map, x - 1, y);
		ft_floodfill(map, x, y + 1);
		ft_floodfill(map, x, y - 1);
		ft_floodfill(map, x + 1, y + 1);
		ft_floodfill(map, x + 1, y - 1);
		ft_floodfill(map, x - 1, y + 1);
		ft_floodfill(map, x - 1, y - 1);
	}
	return (map);
}

int			ft_validate_map(t_master *m)
{
	m->input.x = ft_split(m->input.map, '\n');
	printf("pos x: %d, pos y: %d\n", (int)m->game.pos_x, (int)m->game.pos_y);
	m->input.x[(int)m->game.pos_y][(int)m->game.pos_x] = '0';
	m->input.x = ft_floodfill(m->input.x, m->game.pos_x, m->game.pos_y);
	if (ft_check_map(m->input.x) == -1)
		return (-1);
	return (0);
}
