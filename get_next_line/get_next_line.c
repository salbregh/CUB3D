/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sannealbreghs <sannealbreghs@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 11:59:26 by sannealbreg   #+#    #+#                 */
/*   Updated: 2020/05/21 12:10:42 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_storage_updater(char **storage, char **line)
{
	*line = ft_substr_gnl(*storage, 0, ft_strchr_gnl(*storage, '\n'), 0);
	if (!*line)
	{
		free(*storage);
		*storage = 0;
		return (-1);
	}
	*storage = ft_substr_gnl(*storage, ft_strchr_gnl(*storage, '\n') + 1,\
	ft_strl(*storage), 1);
	if (!*storage)
	{
		free(*storage);
		*storage = 0;
		return (-1);
	}
	return (0);
}

int		ft_strchr_gnl(const char *s, int c)
{
	int			i;
	int			len;

	i = 0;
	if (s == NULL)
		return (-1);
	len = ft_strl(s);
	if ((char)c == '\0')
		return (i);
	while (i < len)
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_read_end(char **storage, char **line)
{
	*line = ft_strdup_gnl(*storage);
	free(*storage);
	*storage = 0;
	return (0);
}

int		ft_read_error(char **storage)
{
	free(*storage);
	*storage = 0;
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*storage;
	int			readvalue;

	if (storage == NULL)
		storage = ft_strdup_gnl("");
	if (fd < 0 || !line || !storage)
		return (-1);
	while (ft_strchr_gnl(storage, '\n') < 0)
	{
		readvalue = read(fd, buf, BUFFER_SIZE);
		if (readvalue < 0)
			return (ft_read_error(&storage));
		if (readvalue <= BUFFER_SIZE)
			buf[readvalue] = '\0';
		if (readvalue == 0)
			return (ft_read_end(&storage, line));
		storage = ft_strjoin_gnl(storage, buf);
		if (!storage)
			return (ft_read_error(&storage));
	}
	if (ft_storage_updater(&storage, line) == -1)
		return (-1);
	return (1);
}
