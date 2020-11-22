/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_input.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/08 12:30:20 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/22 10:42:43 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static char*	ft_trim_paths(char *line, char *set)
{
	char	*tmp1;
	char	*tmp2;
	
	tmp1 = NULL;
	tmp2 = NULL;
	line = ft_strtrim(line, " ");
	if (line[0] != '.')
	{
		tmp1 = ft_strtrim(line, set);
		free(line);
	}
	if (tmp1[0] == ' ')
	{
		tmp2 = ft_strtrim(tmp1, " ");
		free(tmp1);
		return (tmp2);
	}
	return (tmp1);
}

static char*	ft_trim_rest(char *line, char *set)
{
	char	*tmp1;
	char	*tmp2;
	
	tmp1 = NULL;
	tmp2 = NULL;
	line = ft_strtrim(line, " ");
	if (!(line[0] >= '0' && line[0] <= '9'))
	{
		tmp1 = ft_strtrim(line, set);
		free(line);
	}
	if (tmp1[0] == ' ')
	{
		tmp2 = ft_strtrim(tmp1, " ");
		free(tmp1);
		return (tmp2);
	}
	return (tmp1);
}

static int		ft_check_path(char *line, t_master *m)
{
	if (m->input.checkmap == 1)
		return (-1);
	else if (ft_strstr(line, "NO") && m->input.no == NULL)
		m->input.no = ft_trim_paths(line, "NO");
	else if (ft_strstr(line, "SO") && m->input.so == NULL)
		m->input.so = ft_trim_paths(line, "SO");
	else if (ft_strstr(line, "WE") && m->input.we == NULL)
		m->input.we = ft_trim_paths(line, "WE");
	else if (ft_strstr(line, "EA") && m->input.ea == NULL)
		m->input.ea = ft_trim_paths(line, "EA");
	else if (ft_strstr(line, "S") && m->input.sprite == NULL)
		m->input.sprite = ft_trim_paths(line, "S");
	else if (ft_strstr(line, "F") && m->input.floor == NULL)
		m->input.floor = ft_trim_rest(line, "F");
	else if (ft_strstr(line, "C") && m->input.ceiling == NULL)
		m->input.ceiling = ft_trim_rest(line, "C");
	else if (ft_strstr(line, "R") && m->input.resolution == NULL)
		m->input.resolution = ft_trim_rest(line, "R");
	else
		return (-1);
	return (0);
};

static void		ft_check_identifier(char *line, t_master *m)
{
	char		*tmp;
	int			i;

	tmp = m->input.map;
	i = 0;
	if ((ft_strstr(line, "NO")) || (ft_strstr(line, "SO")) ||
		(ft_strstr(line, "WE")) || (ft_strstr(line, "EA")) ||
		(ft_strstr(line, "S ")) || (ft_strstr(line, "R")) ||
		(ft_strstr(line, "C")) || (ft_strstr(line, "F")))
		{
		if (ft_check_path(line, m) == -1)
			ft_error(m, "Problem with the identifiers in the map.");
		}
	else if (ft_strchr(line, '1'))
	{
		if (m->input.lineinmap == 1)
			ft_error(m, "Empty line in map.");
		// while (*line)
		// { // make this ft_strchr iets anders dan al deze waardes
		// 	// if (*line != '1' && *line != '2' && *line != '0' && *line != ' '
		// 	// 	&& *line != 'N' && *line != 'S' && *line != 'E' && *line != 'W')
		// 	// 	ft_error(m, "Invalid character in mapline");
		// 	// line++;
		// }
		m->input.checkmap = 1;
		m->input.map = ft_strjoincub(tmp, line);
		free(tmp);
	}
	else
	{
		if (m->input.checkmap == 1)
			m->input.lineinmap = 1;
		while (line[i])
		{
			if (line[i] != ' ' && line[i] != '\0')
				ft_error(m, "Invalid test in file.");
			i++;
		}
	}
}

int				ft_get_input(int fd, t_master *m)
{
	int		linereturn;
	char	*line;
	
	line = NULL;
	linereturn = 1;
	while (linereturn != 0)
	{
		linereturn = get_next_line(fd, &line);
		ft_check_identifier(&*line, m);
		free(line);
	}
	if (m->input.no == NULL || m->input.so == NULL ||
		m->input.we == NULL || m->input.ea == NULL ||
		m->input.sprite == NULL || m->input.resolution == NULL ||
		m->input.ceiling == NULL || m->input.floor == NULL)
			ft_error(m, "Missing identifier.");
	m->input.mapsplit = ft_split(m->input.map, '\n');
	ft_check_input(m);
	ft_other_identifier(m);
	return (0);
}
