/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_input.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/08 12:30:20 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/01 19:10:35 by salbregh      ########   odam.nl         */
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
	if (ft_strstr(line, "NO") && m->input.no == NULL)
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

static int		ft_check_identifier(char *line, t_master *m)
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
			return (-1);
		}
	else if (ft_strchr(line, '1'))
	{
		printf("goes in else if\n");
		if (m->input.lineinmap == 1)
			return (-1);
		m->input.checkmap = 1;
		m->input.map = NULL;
		m->input.map = ft_strjoincub(tmp, line);
		printf("goes in with: %s\n", line);
		printf("tmp: %s\n", tmp);
		printf("MAP:\n%s$\n", m->input.map);
		tmp = NULL;
		free(tmp);
	}
	else
	{
		printf("goes in else\n");
		if (m->input.checkmap == 1)
			m->input.lineinmap = 1;
		while (line[i])
		{
			if (line[i] != ' ' && line[i] != '\0')
				return (-1);
			i++;
		}
	}
	return (0);
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
		printf("Line: %s\n", &*line);
		if (ft_check_identifier(&*line, m) == -1)
			return (-1);
		free(line);
	}
	if (m->input.no == NULL || m->input.so == NULL ||
		m->input.we == NULL || m->input.ea == NULL ||
		m->input.sprite == NULL || m->input.resolution == NULL ||
		m->input.ceiling == NULL || m->input.floor == NULL)
			return (-1);
	m->input.mapsplit = ft_split(m->input.map, '\n');
	if (ft_check_input(m) == -1 || ft_other_identifier(m) == -1)
		return (-1);
	return (0);
}
