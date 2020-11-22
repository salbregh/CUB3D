# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: salbregh <salbregh@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/06/25 15:16:40 by salbregh      #+#    #+#                  #
<<<<<<< HEAD
#    Updated: 2020/11/22 12:18:33 by salbregh      ########   odam.nl          #
=======
#    Updated: 2020/11/21 22:49:46 by salbregh      ########   odam.nl          #
>>>>>>> c3ee3fa123f37c553e158ec1ee6ed164df4b5181
#                                                                              #
# **************************************************************************** #

NAME =		cub3D

SRCS =		main.c \
			./movement/ft_start_raycasting.c \
			./movement/movement.c \
			./movement/more_movement.c \
			./movement/mlx_hooks.c \
			./movement/draw_colors.c \
			./movement/textures.c \
			./movement/load_pictures.c \
			./movement/sprites.c \
			./movement/set_sprites.c \
			./parser/get_input.c \
			./parser/check_input.c \
			./parser/floodfill.c \
			./parser/check_more_input.c \
			./parser/set_colors.c \
			error.c \
			save.c \
			sort_struct.c
			
OFILES =	$(SRCS:.c=.o)

INCLUDES =	./get_next_line \
			./libft \
			./mlx
			
all:		$(OFILES) $(INCLUDES)
			make -C libft/
			cp libft/libft.a .
			make -C mlx/
			cp mlx/libmlx.dylib .
			make -C get_next_line/
			cp get_next_line/libgnl.a .
			$(CC) -Lmlx -lmlx -Llibft -lft -Lget_next_line -lgnl -framework\
			OpenGL -framework AppKit -o $(NAME) $(OFILES) -Wall -Werror -Wextra -g -fsanitize=address

%.o:		%.c
			gcc -Ilibft -Imlx -c $< -o $@ -Wall -Werror -Wextra 
			#-g -fsanitize=address

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
