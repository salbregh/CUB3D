/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 13:09:19 by salbregh      #+#    #+#                 */
/*   Updated: 2020/11/30 19:42:00 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"
# include <math.h>

typedef struct		s_move
{
	int				up;
	int				down;
	int				left;
	int				right;
	int				rotate_left;
	int				rotate_right;
}					t_move;

typedef struct		s_vars
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bpp;
	int				ll;
	int				endian;
	void			*tex_no;
	char			*addr_no;
	int				w_no;
	int				h_no;
	int				bpp_no;
	int				ll_no;
	void			*tex_so;
	char			*addr_so;
	int				w_so;
	int				h_so;
	int				bpp_so;
	int				ll_so;
	void			*tex_ea;
	char			*addr_ea;
	int				w_ea;
	int				h_ea;
	int				bpp_ea;
	int				ll_ea;
	void			*tex_we;
	char			*addr_we;
	int				w_we;
	int				h_we;
	int				bpp_we;
	int				ll_we;
	void			*tex_;
	char			*addr_;
	int				w_;
	int				h_;
	int				bpp_;
	int				ll_;
	unsigned int	color;
	double			wall_x;
	double			tex_step;
	int				tex_x;
	int				tex_y;
	double			tex_pos;
}					t_vars;

typedef struct		s_sprite
{
	void			*spr;
	char			*addr_spr;
	int				w_spr;
	int				h_spr;
	int				bpp_spr;
	int				ll_spr;
	int				numb;
	double			*perparray;
	double			*distance;
	double			**sprite;
	double			sprite_x;
	double			sprite_y;
	double			inverse;
	double			trans_x;
	double			trans_y;
	int				screen_x;
	int				height;
	int				width;
	int				drawstart_y;
	int				drawend_y;
	int				drawstart_x;
	int				drawend_x;
	int				tex_x;
	int				tex_y;
	unsigned int	color;
}					t_sprite;

typedef struct		s_input
{
	int				save;
	unsigned int	savecolor;
	char			*no;
	char			*so;
	char			*ea;
	char			*we;
	char			*sprite;
	char			*ceiling;
	int				c[3];
	char			*floor;
	int				f[3];
	char			*res;
	int				which;
	char			*map;
	int				maplines;
	int				checkmap;
	int				lineinmap;
	char			**mapsplit;
	char			**x;
}					t_input;

typedef struct		s_game
{
	intmax_t			sh;
	intmax_t			sw;
	int				draw_start;
	int				draw_end;
	int				ceilingcolor;
	int				floorcolor;
	int				line_height;
	double			pos_x;
	double			pos_y;
	char			pos;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			raydir_x;
	double			raydir_y;
	int				map_x;
	int				map_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	double			perpwalldist;
	int				step_x;
	int				step_y;
	int				side;
}					t_game;

typedef struct		s_master
{
	t_vars			vars;
	t_game			game;
	t_move			move;
	t_input			input;
	t_sprite		sprite;
}					t_master;

void				ft_start_raycasting(t_master *master);
void				ft_save(t_master *m);
void				ft_error(t_master *m, char *message);

// raycasting
int					key_press(int keycode, t_master *master);
int					close_button(t_master *master);
int					key_release(int keycode, t_master *m);
int					move(t_master *m);
int					move_up(t_master *m);
int					move_down(t_master *m);
int					move_rigth(t_master *m);
int					move_left(t_master *m);
int					rotate_right(t_master *m);
int					rotate_left(t_master *m);
void				ft_two_back(t_master *m, int which);
void				my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
void				ft_my_pixel_get(t_master *m, int x, int y);
void				ft_my_spritepixel_get(t_master *m, int x, int y);
void				my_mlx_spritepixel_put(t_sprite *sprite, int x,
					int y, int color);
void				ft_my_savepixel_get(t_master *m, int x, int y);
void				ft_draw(t_master *m, int x);

// PARSER
void				ft_get_input(int fd, t_master *m);
void				ft_check_input(t_master *m);
void				ft_validate_map(t_master *m);
void				ft_other_identifier(t_master *m);
void				ft_set_colors(t_master *m);
void				ft_check_identifier(char *line, t_master *m);

// texture crap
void				ft_load_pictures(t_master *m);
void				ft_texturing(t_master *m, int x);

// sprites
void				ft_sprites(t_master *m);
void				ft_set_sprites(t_master *m, int x, int y);
void				ft_sort_sprites(t_master *m, int i, int j);
void				set_array(t_master *m);

void				ft_sort_master(t_master *m, int free);
void				ft_null_sprite(t_sprite *sprite);
void				ft_null_vars(t_vars *vars);
void				ft_null_move(t_move *move);
void				ft_null_game(t_game *game);
void				ft_null_input(t_input *input);
void				ft_free_all(t_master *m);
void				ft_draw_sprites(t_master *m);

#endif
