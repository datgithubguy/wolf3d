/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mooves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 21:29:15 by bal-khan          #+#    #+#             */
/*   Updated: 2015/12/11 21:29:19 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_moove(t_env *e)//, int key)
{
	float	truc;

	truc = (0.3 / (float)e->fps) * 20;
	if (truc >= 0.5)
		truc = 0.5;
	if ((e->mooveu == 1) && e->acceuil)
	{
		ft_step_sound(e);
		if (!ft_strcmp("0", e->map[(int)(e->pos_player_x + e->dir_x * truc)]\
			[(int)e->pos_player_y]))
			e->pos_player_x += e->dir_x * truc;
		if (!ft_strcmp("0", e->map[(int)e->pos_player_x]\
			[(int)(e->pos_player_y + e->dir_y * truc)]))
			e->pos_player_y += e->dir_y * truc;
	}
	if ((e->mooved == 1) && e->acceuil)
	{
		ft_step_sound(e);
		if (!ft_strcmp("0", e->map[(int)(e->pos_player_x - e->dir_x * truc)]\
			[(int)e->pos_player_y]))
			e->pos_player_x -= e->dir_x * truc;
		if (!ft_strcmp("0", e->map[(int)e->pos_player_x]\
			[(int)(e->pos_player_y - e->dir_y * truc)]))
			e->pos_player_y -= e->dir_y * truc;
	}
}

void	ft_rotat(t_env *e)//, int key)
{
	float	truc;

	truc = ((10 / (float)e->fps) > 1) ? (1) : (4 / (float)e->fps);
	if ((e->rotr == 1) && e->acceuil)
	{
		e->old_dir_x = e->dir_x;
		e->dir_x = e->dir_x * cos(-1 * truc) - e->dir_y * sin(-1 * truc);
		e->dir_y = e->old_dir_x * sin(-1 * truc) + e->dir_y * cos(-1 * truc);
		e->old_plan_cam_x = e->plan_cam_x;
		e->plan_cam_x = e->plan_cam_x * cos(-1 * truc) -\
		e->plan_cam_y * sin(-1 * truc);
		e->plan_cam_y = e->old_plan_cam_x * sin(-1 * truc) +\
		e->plan_cam_y * cos(-1 * truc);
	}
	if ((e->rotl == 1) && e->acceuil)
	{
		e->old_dir_x = e->dir_x;
		e->dir_x = e->dir_x * cos(1 * truc) - e->dir_y * sin(1 * truc);
		e->dir_y = e->old_dir_x * sin(1 * truc) + e->dir_y * cos(1 * truc);
		e->old_plan_cam_x = e->plan_cam_x;
		e->plan_cam_x = e->plan_cam_x * cos(1 * truc) -\
		e->plan_cam_y * sin(1 * truc);
		e->plan_cam_y = e->old_plan_cam_x * sin(1 * truc) +\
		e->plan_cam_y * cos(1 * truc);
	}
}
