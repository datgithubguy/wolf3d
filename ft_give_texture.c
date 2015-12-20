/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 03:01:16 by bal-khan          #+#    #+#             */
/*   Updated: 2015/12/14 03:01:18 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

unsigned long	give_texture(t_env *e, double hitx, int y)
{
	double hity;

	hity = abs((y * 2 - e->s_y + e->height) * (e->sprite_sy / 2)\
				/ e->height - 1);
	e->color = ((0x000000FF & e->tex[(int)hitx * 4\
				+ (int)hity * 1 * e->size_line_sprt + 2])
				| (0x0000FF00 & e->tex[(int)hitx * 4\
				+ (int)hity * 1 * e->size_line_sprt + 1] << 8)
				| (0x00FF0000 & e->tex[(int)hitx * 4\
				+ (int)hity * 1 * e->size_line_sprt] << 16));
	if (e->side && e->dir_ray_y > 0)
		e->color ^= 0x00FF0000;
	hitx = (hitx / e->sprite_sx) * e->gif_sx;
	hity = abs((y * 2 - e->s_y + e->height) * (e->gif_sy / 2)\
				/ e->height - 1);
	e->tgif = mlx_get_data_addr(e->gif[e->d], &e->gif_bbp, &e->gif_size_line,
								&e->endian);
	if (e->side && e->dir_ray_y < 0)
		e->color = ((0x000000FF & e->tgif[(int)hitx * 4\
				+ (int)hity * 1 * e->gif_size_line + 2])
				| (0x0000FF00 & e->tgif[(int)hitx * 4\
				+ (int)hity * 1 * e->gif_size_line + 1] << 8)
				| (0x00FF0000 & e->tgif[(int)hitx * 4\
				+ (int)hity * 1 * e->gif_size_line] << 16));
	hitx = (hitx / e->gif_sx) * e->ssprite_sx;
	hity = abs((y * 2 - e->s_y + e->height) * (e->ssprite_sy / 2)\
				/ e->height - 1);
	if (e->dir_ray_x > 0 && !e->side)
		e->color = ((0x000000FF & e->bowser[(int)hitx * 4\
				+ (int)hity * 1 * e->b + 2])
				| (0x0000FF00 & e->bowser[(int)hitx * 4\
				+ (int)hity * 1 * e->b + 1] << 8)
				| (0x00FF0000 & e->bowser[(int)hitx * 4\
				+ (int)hity * 1 * e->b] << 16));
	return (e->color);
}

double			fun(t_env *e)
{
	double	hitx;

	if (e->side)
		hitx = e->pos_ray_x + ((e->y_map - e->pos_ray_y\
			+ (1 - e->fact_y) / 2) / e->dir_ray_y) * e->dir_ray_x;
	else
		hitx = e->pos_ray_y + ((e->x_map - e->pos_ray_x\
			+ (1 - e->fact_x) / 2) / e->dir_ray_x) * e->dir_ray_y;
	hitx = hitx - (int)hitx;
	hitx = (int)(hitx * (double)(e->sprite_sx));
	return (hitx);
}
