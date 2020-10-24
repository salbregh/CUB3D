/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_more_input.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/21 13:20:16 by salbregh      #+#    #+#                 */
/*   Updated: 2020/10/24 14:50:53 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int	ft_check_string(char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (-1);
		str++;
	}
	return (0);
}

static int	ft_get_resolution(char *res, t_master *m)
{
	char	*width;
	char	*height;
	int 	i;
	
	i = 0;
	while (res[i] != ' ')
		i++;
	width = ft_substr(res, 0, i);
	if (ft_check_string(width) == -1)
		return (-1);
	printf("value of width: %s\n", width);
	m->game.sw = ft_atoi(width);
	while (res[i] == ' ')
		i++;
	height = ft_substr(res,i , ft_strlen(res));
	printf("value of heigth: %s\n", height);
	if (ft_check_string(height) == -1)
		return (-1);
	m->game.sh = ft_atoi(height);
	free(width);
	free(height);
	if (m->game.sw == 0 || m->game.sh == 0)
		return (-1);
	return (0);
}

static int	ft_get_more_color(char *c1, char* c2, char* c3,
			t_master *m, int which)
{
	if (ft_check_string(c1) == -1 || ft_check_string(c2) == -1 ||
	ft_check_string(c3) == -1)
		return (-1);
	if (which == 0) // color for floor
	{
		m->input.f[0] = ft_atoi(c1);
		free(c1);
		m->input.f[1] = ft_atoi(c2);
		free(c2);
		m->input.f[2] = ft_atoi(c3);
		free(c3);
	}
	else if (which == 1) // color for ceiling
	{
		m->input.c[0] = ft_atoi(c1);
		free(c1);
		m->input.c[1] = ft_atoi(c2);
		free(c2);
		m->input.c[2] = ft_atoi(c3);
		free(c3);
	}
	return (0);
}

static int	ft_get_color(char *color, t_master *m, int which)
{
	char	*check1;
	char	*check2;
	char	*check3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (color[i] != ' ' && color[i] != ',')
		i++;
	check1 = ft_substr(color, 0, i);
	while (color[i] == ' ' || color[i] == ',')
		i++;
	j = i;
	while (color[i] != ' ' && color[i] != ',')
		i++;
	check2 = ft_substr(color, j, i - j);
	while (color[i] == ' ' || color[i] == ',')
		i++;
	check3 = ft_substr(color, i, ft_strlen(color) - i);
	if (ft_get_more_color(check1, check2, check3, m, which) == -1)
		return (-1);
	return (0);
}

int			ft_other_identifier(t_master *m)
{
	if ((ft_get_resolution(m->input.resolution, m)) == -1 ||
	(ft_get_color(m->input.floor, m, 0) == -1) ||
	(ft_get_color(m->input.ceiling, m, 1) == -1))
		return (-1);
	if (ft_set_colors(m) == -1)
		return (-1);
	// printf("input floor color:\nf0: %i\nf1: %i\nf2: %i\n", m->input.f[0], m->input.f[1], m->input.f[2]);
	// printf("input ceiling color:\nf0: %i\nf1: %i\nf2: %i\n", m->input.c[0], m->input.c[1], m->input.c[2]);
	return (0);
}
