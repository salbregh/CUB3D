/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 13:22:38 by salbregh      #+#    #+#                 */
/*   Updated: 2020/05/21 12:10:49 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int				get_next_line(int fd, char **line);
char			*ft_substr_gnl(char *s, unsigned int start,
				size_t len, int call);
char			*ft_strjoin_gnl(char *s1, char *s2);
char			*ft_strdup_gnl(const char *s1);
int				ft_strchr_gnl(const char *s, int c);
size_t			ft_strl(const char *s);
char			*ft_free_me(char **s);

#endif
