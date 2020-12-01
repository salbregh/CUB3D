# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: salbregh <salbregh@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/22 13:08:56 by salbregh      #+#    #+#                  #
#    Updated: 2020/12/01 22:30:25 by salbregh      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =		cub3D

SRCS =		./srcs/main.c \
			./srcs/ft_start_raycasting.c \
			./srcs/movement.c \
			./srcs/more_movement.c \
			./srcs/mlx_hooks.c \
			./srcs/draw_colors.c \
			./srcs/textures.c \
			./srcs/load_pictures.c \
			./srcs/sprites.c \
			./srcs/set_sprites.c \
			./srcs/get_input.c \
			./srcs/check_input.c \
			./srcs/floodfill.c \
			./srcs/check_more_input.c \
			./srcs/set_colors.c \
			./srcs/save.c \
			./srcs/sort_struct.c

OFILES =	$(SRCS:.c=.o)

INCLUDES =	./get_next_line \
			./libft \
			./mlx

all:		$(NAME)

$(NAME):	$(OFILES) $(INCLUDES)
			make -C libft/
			cp libft/libft.a .
			make -C mlx/
			cp mlx/libmlx.dylib .
			make -C get_next_line/
			cp get_next_line/libgnl.a .
			$(CC) -Lmlx -lmlx -Llibft -lft -Lget_next_line -lgnl \
			-o $(NAME) $(OFILES) -Wall -Werror -Wextra

%.o:		%.c
			gcc -Ilibft -Imlx -c $< -o $@ -Wall -Werror -Wextra

clean:
			/bin/rm -f $(OFILES)
			make clean -C libft/
			make clean -C mlx/
			make clean -C get_next_line

fclean:		clean
			/bin/rm -f mlx/libmlx.dylib
			/bin/rm -f libmlx.dylib
			/bin/rm -f libft/libft.a
			/bin/rm -f libft.a
			/bin/rm -f get_nextline/libgnl.a
			/bin/rm -f libgnl.a
			/bin/rm -f screenshot.bmp
			/bin/rm -f $(NAME)

re:			fclean all
