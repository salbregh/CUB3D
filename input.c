/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/04 18:20:12 by salbregh      #+#    #+#                 */
/*   Updated: 2020/07/10 15:59:01 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


static void	ft_check_input(t_master *m)
{
	printf("south : %s\n", m->input.so);
	printf("north : %s\n", m->input.no);
	printf("west : %s\n", m->input.we);
	printf("east : %s\n", m->input.ea);
	printf("color : %s\n", m->input.color);
	printf("resolution : %s\n", m->input.resolution);
	printf("floor : %s\n", m->input.floor);
	printf("mapstring : %s\n", m->input.mapstr);
	// check positions
}

static void	ft_set_mapstring(char *line, t_master *m)
{
	if (m->input.mapstr == NULL)
		m->input.mapstr = ft_strdup("");
	m->input.mapstr = ft_strjoin(m->input.mapstr, line);
	m->input.mapstr = ft_strjoin(m->input.mapstr, "\n");
}

static int	ft_count_maplines(t_master *m)
{
	int		i;

	i = 0;
	while (m->input.mapsplit[i] != NULL)
		i++;
	m->input.maplines = i; // not used
	return (i);
}

static void	ft_start_position(t_master *m)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < ft_count_maplines(m))
	{
		while (m->input.mapsplit[y][x] != '\0')
		{
			if (m->input.mapsplit[y][x] == 'N' || m->input.mapsplit[y][x] == 'S'
			|| m->input.mapsplit[y][x] == 'E' || m->input.mapsplit[y][x] == 'W')
			{
				if (m->game.pos_x != 0 || m->game.pos_y != 0)
					printf("two starting position, add an error\n\n");
				m->game.pos_x = x + 0.5;
				m->game.pos_y = y + 0.5;
				m->input.mapsplit[y][x] = '0';
			}
			x++;
		}
		y++;
		x = 0;
	}
}

static void	ft_set_mapsplit(t_master *m)
{
	int		i;
	
	i = 0;
	m->input.mapsplit = ft_split(m->input.mapstr, '\n');
	m->input.mapcheck = ft_split(m->input.mapstr, '\n');
	ft_start_position(m);
	while (m->input.mapsplit[i] != NULL)
	{
		printf("mapsplit[%i] : %s\n", i, m->input.mapcheck[i]);
		i++;
	}
	printf("startposition x: %f\n", m->game.pos_x);
	printf("startposition y: %f\n", m->game.pos_y);
}

int			ft_input_main(int fd, t_master *m)
{
	int		linereturn;

	linereturn = 1;
	// set the struct for path to null first or nah?
	// ft_find_paths(fd, linereturn, m);
	char 	*line;

	line = NULL;
	while (linereturn != 0)
	{
		linereturn = get_next_line(fd, &line);
		if (ft_strstr(line, "SO"))
			ft_set_south(m, line);
		else if (ft_strstr(line, "NO"))
			ft_set_north(m, line);
		else if (ft_strstr(line, "WE"))
			ft_set_west(m, line);
		else if (ft_strstr(line, "EA"))
			ft_set_east(m, line);
		else if (ft_strstr(line, "S "))
			ft_set_sprite(m, line);
		else if (ft_strstr(line, "R"))
			m->input.resolution = line;
		else if (ft_strstr(line, "C"))
			m->input.color = line;
		else if (ft_strstr(line, "F"))
			m->input.floor = line;
		else if (ft_strchr(line, '1') || ft_strchr(line, '0') || ft_strchr(line, '2'))
			ft_set_mapstring(line, m);
		// check for a map underneath the map
	}
	ft_check_input(m);
	ft_set_mapsplit(m);
	return (0);
}
