/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 21:31:32 by bal-khan          #+#    #+#             */
/*   Updated: 2015/12/11 21:31:36 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_norme(t_env *e)
{
	e->dir_ray_x = e->dir_x + e->plan_cam_x * e->camera_x;
	e->dir_ray_y = e->dir_y + e->plan_cam_y * e->camera_x;
	e->delta_dist_x = sqrt(1 + (e->dir_ray_y * e->dir_ray_y) \
		/ (e->dir_ray_x * e->dir_ray_x));
	e->delta_dist_y = sqrt(1 + (e->dir_ray_x * e->dir_ray_x) \
		/ (e->dir_ray_y * e->dir_ray_y));
}

void	ft_init_dda(t_env *e)
{
	ft_norme(e);
	if (e->dir_ray_x < 0)
	{
		e->fact_x = -1;
		e->dist_x = (e->pos_ray_x - e->x_map) * e->delta_dist_x;
	}
	else
	{
		e->fact_x = 1;
		e->dist_x = (1.0 - e->pos_ray_x + e->x_map) * e->delta_dist_x;
	}
	if (e->dir_ray_y < 0)
	{
		e->fact_y = -1;
		e->dist_y = (e->pos_ray_y - e->y_map) * e->delta_dist_y;
	}
	else
	{
		e->fact_y = 1;
		e->dist_y = (1.0 - e->pos_ray_y + e->y_map) * e->delta_dist_y;
	}
}

void	ft_dda(t_env *e)
{
	while (!e->hit_wall)
	{
		if (e->dist_x < e->dist_y)
		{
			e->dist_x += e->delta_dist_x;
			e->x_map += e->fact_x;
			e->side = 0;
		}
		else
		{
			e->dist_y += e->delta_dist_y;
			e->y_map += e->fact_y;
			e->side = 1;
		}
		if (!ft_strcmp(e->map[e->x_map][e->y_map], "0"))
			e->hit_wall = 0;
		else if (!ft_strcmp(e->map[e->x_map][e->y_map], "1"))
			e->hit_wall = 1;
	}
}

void	ft_ddda(t_env *e)
{
	while (!e->hit_wall)
	{
		if (e->dist_x < e->dist_y)
		{
			e->dist_x += e->delta_dist_x;
			e->x_map += e->fact_x;
			e->side = 0;
		}
		else
		{
			e->dist_y += e->delta_dist_y;
			e->y_map += e->fact_y;
			e->side = 1;
		}
		if (!ft_strcmp(e->map[e->x_map][e->y_map], "0"))
			e->hit_wall = 0;
		else if (!ft_strcmp(e->map[e->x_map][e->y_map], "1"))
			e->hit_wall = 1;
		else if (!ft_strcmp(e->map[e->x_map][e->y_map], "2"))
			e->hit_wall = 2;
	}
}
