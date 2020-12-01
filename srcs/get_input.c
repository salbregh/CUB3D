/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_input.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 19:34:45 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/30 20:40:16 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static char		*ft_trim_paths(char *line, char *set)
{
	char	*tmp1;
	int		i;
	char	*tmp2;

	tmp2 = NULL;
	i = 0;
	tmp1 = ft_strtrim(line, set);
	if (tmp1[0] == ' ' || tmp1[ft_strlen(tmp1)] == ' ')
	{
		tmp2 = ft_strtrim(tmp1, " ");
		free(tmp1);
		return (tmp2);
	}
	return (tmp1);
}

static char		*ft_trim_rest(char *line, char *set)
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

static void		ft_check_path(char *line, t_master *m)
{
	if (m->input.checkmap == 1)
		ft_error(m, "Identifiers found after map.");
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
	else if (ft_strstr(line, "R") && m->input.res == NULL)
		m->input.res = ft_trim_rest(line, "R");
	else
		ft_error(m, "Problem with the identifiers in the map.");
}

static void		ft_check_mapline(t_master *m, char *tmp, char *line)
{
	char *check;

	check = line;
	if (m->input.lineinmap == 1)
		ft_error(m, "Empty line in map.");
	while (*check)
	{
		if (*check != ' ' && *check != '1' && *check != '2' && *check != '0'
		&& *check != 'E' && *check != 'N' && *check != 'S' && *check != 'W')
			ft_error(m, "Invalid character in map");
		check++;
	}
	m->input.checkmap = 1;
	m->input.map = ft_strjoincub(tmp, line);
	free(tmp);
}

void			ft_check_identifier(char *line, t_master *m)
{
	char		*tmp;
	int			i;

	tmp = m->input.map;
	i = 0;
	if (ft_strstr(line, "NO") || ft_strstr(line, "SO") || ft_strstr(line, "WE")
	|| ft_strstr(line, "EA") || ft_strstr(line, "S ") ||
	ft_strstr(line, "R") || ft_strstr(line, "C") || ft_strstr(line, "F"))
		ft_check_path(line, m);
	else if (ft_strchr(line, '1'))
		ft_check_mapline(m, tmp, line);
	else
	{
		if (m->input.checkmap == 1)
			m->input.lineinmap = 1;
		while (line[i])
		{
			if (line[i] != ' ' && line[i] != '\0')
				ft_error(m, "Invalid character in file.");
			i++;
		}
	}
}
