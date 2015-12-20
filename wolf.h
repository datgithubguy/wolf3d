/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 20:02:41 by bal-khan          #+#    #+#             */
/*   Updated: 2015/12/11 20:03:01 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include "minilibx_macos/mlx.h"
# include <fcntl.h>
# include "./gnl/get_next_line.h"
# include <math.h>
# include <time.h>

# define S_X 1000
# define S_Y 500

typedef struct	s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bbp;
	int				bbbp;
	int				size_line;
	int				endian;
	char			***map;
	int				sound;

	void			*anim[4];
	void			*gif[10];
	int				gif_sx;
	int				gif_sy;
	int				gif_size_line;
	int				gif_bbp;
	char			*tgif;
	char			*tex;
	int				d;
	char			*bowser;
	int				a;
	int				b;
	int				c;
	char			*alphab;
	int				bbp_sprt;
	int				size_line_sprt;
	int				ssize_line_sprt;
	int				sprite_sx;
	int				sprite_sy;
	int				ssprite_sx;
	int				ssprite_sy;

	double			pos_player_x;
	double			pos_player_y;
	double			x_old;
	double			y_old;

	double			pos_ray_x;
	double			pos_ray_y;

	double			dir_x;
	double			dir_y;
	double			old_dir_x;

	double			dir_ray_x;
	double			dir_ray_y;

	double			plan_cam_x;
	double			plan_cam_y;
	double			old_plan_cam_x;

	double			camera_x;

	int				x_map;
	int				y_map;

	double			dist_x;
	double			dist_y;

	double			delta_dist_x;
	double			delta_dist_y;

	int				fact_x;
	int				fact_y;

	int				hit_wall;
	char			side;
	double			wall;

	int				height;
	int				color;
	int				draw_start;
	int				draw_end;
	int				darkness;
	int				torch_found;
	int				doors_opened;
	int				acceuil;

	int				s_x;
	int				s_y;
	int				pos_menu;
	int				s;
	int				knife;
	int				fps;
	int				mooved;
	int				mooveu;
	int				rotr;
	int				rotl;

	int				pos_sp_x;
	int				pos_sp_y;
	int				x_mid_sp;
	int				delta_size_sp;
	float			dist_pl_sp;
}				t_env;

int				magic(int key, t_env *e);
char			***three_dims(int fd, int size);
int				big(int fd);
int				key_hook(int key, t_env *e);
void			ft_rotat(t_env *e);//, int key);
void			ft_moove(t_env *e);//, int key);
void			ft_step_sound(t_env *e);
void			ft_modes(t_env *e, int key);
void			ft_menu(t_env *e, int key);
void			ft_resize(t_env *e);
void			free_map(t_env *e);
void			free_knife(t_env *e);
void			ft_exit(int ret, t_env *e);
void			get_pos(double x, double y, t_env *e, int flagg);
unsigned long	give_color(t_env *e);
void			ft_put_in_img(t_env *e, int x, int y, double hitx);
int				draw(t_env *e);
void			ft_truc(t_env *e);
void			ft_machin(t_env *e, int x);
void			ft_dda(t_env *e);
void			ft_ddda(t_env *e);
void			ft_init_dda(t_env *e);
void			ft_norme(t_env *e);
int				expose_hook(t_env *e);
void			ft_hello(t_env *e);
void			ft_real_string_put(t_env *e, char *str, int x, int y);
void			put_pix_img(t_env *e, int x, int y, unsigned long color);
t_env			init_mlx(int s_x, int s_y);
void			get_anims(t_env *e);
void			init_env(t_env *e);
char			***ft_give_map(void);
unsigned long	give_texture(t_env *e, double hitx, int y);
double			fun(t_env *e);
void			ma_bite(t_env *e, int c);
int				fun_key(int	key);
int				fun_key_norme(int key);
void			ft_put_knife(t_env *e);
void			ennemy(t_env *e);
void			find_sprite(t_env *e);
void			giffter(t_env *e);
void			draw_hud(t_env *e);
void			put_pix_img_hud(t_env *e, int x, int y, unsigned long color);

#endif
