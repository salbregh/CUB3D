/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/25 16:31:18 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/06 18:53:41 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"

# include <math.h>
# include <stdio.h> // DELETE

typedef struct	s_move
{
	int			up;
	int			down;
	int			left;
	int			right;
	int			rotate_left;
	int			rotate_right;
}				t_move;

typedef struct	s_vars
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			ll;
	int			endian;
	void		*texture1;
	char		*addr1;
	int			w1;
	int			h1;
	int			bpp1;
	int			ll1;
	unsigned int 		color; // nodig?
	float		wall_x;
	float		tex_step;
	int			line_height;
	int			tex_x;
	int			tex_y;
	int			tex_pos;
}				t_vars;

typedef struct	s_input
{
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	char		*sprite;
	char		*ceiling;
	int			c[3];
	char		*floor;
	int			f[3];
	char		*resolution;
	char		*map;
	int			checkmap;
	int			lineinmap;
	char		**mapsplit;
	char		**x;
}				t_input;

typedef struct	s_game
{
	int			x;
	int			sh;
	int			sw;
	int			draw_start;
	int			draw_end;
	int			ceilingcolor;
	int			floorcolor;
	int			line_height;
	double		pos_x;
	double		pos_y;
	char		pos;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		perpwalldist;
	int			step_x;
	int			step_y;
	int			side;
}				t_game;

typedef struct	s_master
{
	t_vars		vars;
	t_game		game;
	t_move		move;
	t_input		input;
}				t_master;

void	ft_start_raycasting(t_master *master);
void	ft_sort_master(t_master *m);
void	ft_error(t_master *m, char *message);

// MOVEMENT .C
int		key_press(int keycode, t_master *master);
int		close_button(t_master *master);
int		key_release(int keycode, t_master *m);
int		move_bitch(t_master *m);
int		move_up(t_master *m);
int		move_down(t_master *m);
int		move_rigth(t_master *m);
int		move_left(t_master *m);
int		rotate_right(t_master *m);
int		rotate_left(t_master *m);
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);

// PARSER
int				ft_get_input(int fd, t_master *m);
int				ft_check_input(t_master *m);
int				ft_validate_map(t_master *m);
int				ft_other_identifier(t_master *m);
int				ft_set_colors(t_master *m);

// texture crap
int				ft_load_texture(t_master *m);
void			ft_my_pixel_get(t_master *m, int y, int x);
void			ft_texturing(t_master *m, int x, unsigned int color);

#endif
