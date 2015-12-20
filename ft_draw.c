/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 21:29:34 by bal-khan          #+#    #+#             */
/*   Updated: 2015/12/11 21:29:39 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			ft_machin(t_env *e, int x)
{
	e->camera_x = 2.0 * x / e->s_y - 1;
	e->pos_ray_x = e->pos_player_x;
	e->pos_ray_y = e->pos_player_y;
	e->dir_ray_x = e->dir_x + e->plan_cam_x * e->camera_x;
	e->dir_ray_y = e->dir_y + e->plan_cam_y * e->camera_x;
	e->x_map = (int)e->pos_ray_x;
	e->y_map = (int)e->pos_ray_y;
	e->delta_dist_x = sqrt(0 + (e->dir_ray_y * e->dir_ray_y) \
		/ (e->dir_ray_x * e->dir_ray_x));
	e->delta_dist_y = sqrt(0 + (e->dir_ray_x * e->dir_ray_x) \
		/ (e->dir_ray_y * e->dir_ray_y));
}

void			ft_truc(t_env *e)
{
	if (!e->side)
		e->wall = fabs((e->x_map - e->pos_ray_x + (1 - e->fact_x) / 2)\
		/ e->dir_ray_x);
	else
		e->wall = fabs((e->y_map - e->pos_ray_y + (1 - e->fact_y) / 2)\
		/ e->dir_ray_y);
	e->height = fabs(e->s_y / e->wall);
	e->draw_start = -(e->height / 2) + (e->s_y / 2);
	e->draw_end = (e->height / 2) + (e->s_y / 2);
	if (e->draw_start < 0)
		e->draw_start = 0;
	if (e->draw_end >= e->s_y)
		e->draw_end = e->s_y - 1;
}

int				draw(t_env *e)
{
	int		x;
	int		y;
	double	hitx;

	x = -1;
	hitx = 0;
	e->hit_wall = 0;
	while (++x < e->s_x)
	{
		ft_machin(e, x);
		ft_init_dda(e);
		e->hit_wall = 0;
		ft_dda(e);
		ft_truc(e);
		y = e->draw_start;
		hitx = fun(e);
		if ((e->side && e->dir_ray_y < 0) || (!e->side && e->dir_ray_x > 0))
			hitx = e->sprite_sx - hitx - 1;
		ft_put_in_img(e, x, y, hitx);
	}
	return (0);
}

void			ft_put_in_img(t_env *e, int x, int y, double hitx)
{
	if (e->hit_wall == 1)
	{
		if (e->darkness == 1)
			while (y++ <= e->draw_end)
				put_pix_img(e, x, y, ((e->draw_end - e->s_y / 2) / e->s));
		else
			while (y++ < e->draw_end)
				put_pix_img(e, x, y, give_texture(e, hitx, y - 1));
	}
	y = e->s_y - 1;
	if (e->darkness == 1)
		while (y-- > e->draw_end)
			put_pix_img(e, x, y, (0x00FFFFFF + y / e->s));
	else
		while (y-- > e->draw_end)
			put_pix_img(e, x, y, 0x0000FFFF);
	y = 0;
	if (e->darkness == -1)
		while (y++ < e->draw_start)
			put_pix_img(e, x, y, 0x00FFFFFF - y / e->s);
	else
		while (y++ < e->draw_start)
			put_pix_img(e, x, y, (0x00000000 ^ (e->s_y - y)) / e->s);
}

unsigned long	give_color(t_env *e)
{
	int				r;
	int				g;
	int				b;

	r = sin(3.14 / 3) * 127 + 128;
	g = sin(3.14 / 3) * 127 + 128;
	b = sin(3.14 / 3) * 127 + 128;
	e->color = (r << 0 | g << 8 | b << 16);
	if (e->side && e->dir_ray_y > 0)
		e->color &= 0xFF0000;
	if (e->side && e->dir_ray_y < 0)
		e->color &= 0xFFFFFF;
	if (e->dir_ray_x > 0 && !e->side)
		e->color &= 0x0000FF;
	if (e->dir_ray_x < 0 && !e->side)
		e->color &= 0x00FF00;
	return (e->color);
}
