/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_more_input.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/21 13:20:16 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/18 13:20:56 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	ft_check_string(char *str, t_master *m)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			ft_error(m, "Invalid character.");
		str++;
	}
}

static void	ft_get_resolution(char *res, t_master *m)
{
	char	*width;
	char	*height;
	int		i;

	i = 0;
	while (res[i] != ' ')
		i++;
	width = ft_substr(res, 0, i);
	ft_check_string(width, m);
	m->game.sw = ft_atoi(width);
	// m->sprite.perparray[m->game.sw] = '\0';
	while (res[i] == ' ')
		i++;
	height = ft_substr(res, i, ft_strlen(res));
	ft_check_string(height, m);
	m->game.sh = ft_atoi(height);
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
	ft_get_more_color(check1, check2, check3, m);
}

void		ft_other_identifier(t_master *m)
{
	int		checkx;
	int		checky;
	
	ft_get_resolution(m->input.resolution, m);
	mlx_get_screen_size(m->vars.mlx, &checkx, &checky);
	if (m->game.sw > checkx || m->game.sh > checky)
	{
		m->game.sw = checkx;
		m->game.sh = checky;
	}
	m->sprite.perparray = (double *)malloc((m->game.sw)* sizeof(double) + 1);
	m->input.which = 0;
	ft_get_color(m->input.floor, m);
	m->input.which = 1;
	ft_get_color(m->input.ceiling, m);
	ft_set_colors(m);
}
