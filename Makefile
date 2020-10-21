# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: salbregh <salbregh@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/06/25 15:16:40 by salbregh      #+#    #+#                  #
#    Updated: 2020/10/21 11:54:17 by salbregh      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =		cub3D

SRCS =		main.c \
			my_pixel_put.c \
			ft_start_raycasting.c \
			movement.c \
			./parser/get_input.c \
			./parser/check_input.c \
			./parser/floodfill.c \
			sort_struct.c
			# input.c\
			# paths.c

OFILES =	$(SRCS:.c=.o)

INCLUDES =	./get_next_line \
			./libft \
			./mlx

			# /Users/sannealbreghs/Desktop/CUB3D/get_next_line \
			# /Users/sannealbreghs/Desktop/CUB3D/libft \
			# /Users/sannealbreghs/Desktop/CUB3D/mlx

			
			
all:		$(OFILES) $(INCLUDES)
			make -C libft/
			cp libft/libft.a .
			make -C mlx/
			cp mlx/libmlx.dylib .
			make -C get_next_line/
			cp get_next_line/libgnl.a .
			$(CC) -Lmlx -lmlx -Llibft -lft -Lget_next_line -lgnl -framework \
			OpenGL -framework AppKit -o $(NAME) $(OFILES) -Wall -Werror -Wextra

%.o:		%.c
			gcc -Ilibft -Imlx -c $< -o $@ -Wall -Werror -Wextra

clean:
			/bin/rm -f $(OFILES)
			make clean -C libft/
			make clean -C mlx/
			make clean -C get_next_line/

fclean:		clean
			/bin/rm -f mlx/libmlx.dylib
			/bin/rm -f libmlx.dylib
			/bin/rm -f libft/libft.a
			/bin/rm -f libft.a
			/bin/rm -f get_nextline/libgnl.a
			/bin/rm -f libgnl.a
			/bin/rm -f $(NAME)

re:			fclean all
