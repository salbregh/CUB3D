/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoincub.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 13:45:13 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/01 19:15:59 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoincub(char const *s1, char const *s2)
{
	char		*str;
	size_t		i;
	size_t		j;

	if (s1 == NULL || s2 == NULL)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (str == NULL)
		return (0);
	i = 0;
	j = 0;
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\n';
	str[i + j + 1] = '\0';
	return (str);
}
