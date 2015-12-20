/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 21:30:34 by bal-khan          #+#    #+#             */
/*   Updated: 2015/12/11 21:30:36 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

char	***ft_give_map(void)
{
	char	***ret;
	int		size;
	int		fd_map;

	fd_map = open("map", O_RDONLY);
	if (fd_map < 0)
		exit(-1);
	size = big(fd_map);
	close(fd_map);
	fd_map = open("map", O_RDONLY);
	if (fd_map < 0)
		exit(-1);
	ret = three_dims(fd_map, size);
	close(fd_map);
	return (ret);
}

void	init_env(t_env *e)
{
	e->knife = 0;
	e->sound = 0;
	e->pos_player_x = 13;
	e->pos_player_y = 26;
	e->pos_ray_x = e->pos_player_x;
	e->pos_ray_y = e->pos_player_y;
	e->dir_x = 1.01;
	e->dir_y = 0.01;
	e->plan_cam_x = 0.01;
	e->plan_cam_y = -0.66;
	e->acceuil = 0;
	e->pos_menu = 0;
	e->fps = 1;
	e->tex = mlx_get_data_addr(e->anim[2], &e->bbp_sprt, &e->size_line_sprt,
								&e->endian);
	ft_bzero(e->tex, e->size_line_sprt * e->sprite_sy);
	e->mooveu = 0;
	e->mooved = 0;
	e->rotl = 0;
	e->rotr = 0;
}

void	get_anims(t_env *e)
{
	if (!(e->anim[0] = mlx_xpm_file_to_image(e->mlx, "no_leaks.xpm",\
		&e->ssprite_sx, &e->ssprite_sy)))
		exit(1);
	if (!(e->bowser = mlx_get_data_addr(e->anim[0], &e->a, &e->b,\
								&e->c)))
		exit(1);
	if (!(e->anim[1] = mlx_xpm_file_to_image(e->mlx, "2.xpm",\
		&e->sprite_sx, &e->sprite_sy)))
		exit(1);
	if (!(e->anim[2] = mlx_xpm_file_to_image(e->mlx, "alphaB.xpm",\
		&e->sprite_sx, &e->sprite_sy)))
		exit(1);
	if (!(e->anim[3] = mlx_xpm_file_to_image(e->mlx, "alphaB.xpm",\
		&e->sprite_sx, &e->sprite_sy)))
		exit(1);
}

t_env	init_mlx(int s_x, int s_y)
{
	t_env	ep;
	t_env	*e;

	e = &ep;
	e->s_x = s_x;
	e->s_y = s_y;
	if (!(e->mlx = mlx_init()))
		exit(1);
	if (!(e->win = mlx_new_window(e->mlx, e->s_x, e->s_y, "Wolf")))
		exit(1);
	if (!(e->img = mlx_new_image(e->mlx, e->s_x, e->s_y)))
		exit(1);
	if (!(e->data = mlx_get_data_addr(e->img, &(e->bbp),
									&(e->size_line), &(e->endian))))
		exit(1);
	get_anims(e);
	e->alphab = mlx_get_data_addr(e->anim[3], &e->bbp_sprt, &e->size_line_sprt,
								&e->endian);
	e->darkness = -1;
	return (ep);
}

void	find_sprite(t_env *e)
{
	e->pos_sp_x = 0;
	while (e->map[e->pos_sp_x])
	{
		e->pos_sp_x += 1;
		e->pos_sp_y = 0;
		while (e->map[e->pos_sp_x][e->pos_sp_y])
		{
			if (!ft_strcmp(e->map[e->pos_sp_x][e->pos_sp_y], "2"))
				return ;
			e->pos_sp_y += 1;
		}
	}
	e->pos_sp_x = -1;
	e->pos_sp_y = -1;
}
