/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_more_input.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/21 13:20:16 by salbregh      #+#    #+#                 */
/*   Updated: 2020/10/22 22:12:41 by salbregh      ########   odam.nl         */
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

static int	ft_get_color(char *color, t_master *m)
{
	char	*check1;
	char	*check2;
	char	*check3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	printf("value of color in ft_get_color: %s\n", color);
	while (color[i] != ' ' && color[i] != ',')
		i++;
	check1 = ft_substr(color, 0, i);
	printf("value of check1: %s\n", check1);
	while (color[i] == ' ' || color[i] == ',')
		i++;
	j = i;
	while (color[i] != ' ' && color[i] != ',')
		i++;
	check2 = ft_substr(color, j, i - j);
	printf("value of check2: %s\n", check2);
	while (color[i] == ' ' || color[i] == ',')
		i++;
	check3 = ft_substr(color, i, ft_strlen(color) - i);
	printf("value of check3: %s\n", check3);
	(void)m;
	return (0);
}

int			ft_other_identifier(t_master *m)
{
	printf("resolution line:\n%s\n", m->input.resolution);
	printf("color ceiling line:\n%s\n", m->input.ceiling);
	printf("color floor line:\n%s\n", m->input.floor);
	// check the color from floor and ceiling
	if ((ft_get_resolution(m->input.resolution, m)) == -1 ||
	(ft_get_color(m->input.floor, m) == -1) ||
	(ft_get_color(m->input.ceiling, m) == -1))
		return (-1);
	return (0);
}
