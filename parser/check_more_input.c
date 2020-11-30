/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_more_input.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 13:11:02 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/30 18:15:27 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	ft_check_string(char *str, t_master *m)
{
	if (!*str)
		ft_error(m, "Invalid map input, value missing in identifier.");
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			ft_error(m, "Invalid character in map.");
		str++;
	}
}

#include <stdio.h>

static void	ft_get_resolution(char *res, t_master *m)
{
	char	*width;
	char	*height;
	int		i;

	i = 0;
	printf("res: %s\n", res);
	while (res[i] != ' ')
		i++;
	width = ft_substr(res, 0, i);
	printf("width: %s\n", width);
	ft_check_string(width, m);
	m->game.sw = ft_atoi(width);
	printf("value of sw: %lu\n", m->game.sw);
	while (res[i] == ' ')
		i++;
	height = ft_substr(res, i, ft_strlen(res));
	ft_check_string(height, m);
	printf("height: %s\n", height);
	m->game.sh = ft_atoi(height);
	printf("value of sh: %lu\n", m->game.sh);
	free(width);
	free(height);
	if (m->game.sw == 0 || m->game.sh == 0)
		ft_error(m, "Error in the resolution.");
}

static void	ft_get_more_color(char *c1, char *c2, char *c3,
			t_master *m)
{
	ft_check_string(c1, m);
	ft_check_string(c2, m);
	ft_check_string(c3, m);
	if (m->input.which == 0)
	{
		m->input.f[0] = ft_atoi(c1);
		free(c1);
		m->input.f[1] = ft_atoi(c2);
		free(c2);
		m->input.f[2] = ft_atoi(c3);
		free(c3);
	}
	else if (m->input.which == 1)
	{
		m->input.c[0] = ft_atoi(c1);
		free(c1);
		m->input.c[1] = ft_atoi(c2);
		free(c2);
		m->input.c[2] = ft_atoi(c3);
		free(c3);
		if (m->input.c[0] > 255 || m->input.c[1] > 255
		|| m->input.c[2] > 255)
			ft_error(m, "Color value incorrect.");
	}
}

static void	ft_get_color(char *color, t_master *m)
{
	char	*check1;
	char	*check2;
	char	*check3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	check1 = NULL;
	check2 = NULL;
	check3 = NULL;
	while (color[i] != ' ' && color[i] != ',')
		i++;
	check1 = ft_substr(color, 0, i);
	while ((color[i] == ' ' || color[i] == ',') && color[i])
		i++;
	j = i;
	while ((color[i] != ' ' && color[i] != ',') && color[i])
		i++;
	check2 = ft_substr(color, j, i - j);
	while ((color[i] == ' ' || color[i] == ',') && color[i])
		i++;
	check3 = ft_substr(color, i, ft_strlen(color) - i);
	ft_get_more_color(check1, check2, check3, m);
}

void		ft_other_identifier(t_master *m)
{
	int		checkx;
	int		checky;

	ft_get_resolution(m->input.res, m);
	if ((m->game.sw > 16384 || m->game.sh > 16384) && m->input.save == 1)
		ft_error(m, "Resolution too big to save");
	mlx_get_screen_size(m->vars.mlx, &checkx, &checky);

	if (m->game.sw > checkx && m->input.save == 0)
		m->game.sw = checkx;
	if (m->game.sh > checky && m->input.save == 0)
		m->game.sh = checky;

	m->sprite.perparray = (double *)malloc((m->game.sw) * sizeof(double) + 1);
	m->input.which = 0;
	ft_get_color(m->input.floor, m);
	m->input.which = 1;
	ft_get_color(m->input.ceiling, m);
	ft_set_colors(m);
}
