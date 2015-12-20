/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_knife.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 10:36:25 by bal-khan          #+#    #+#             */
/*   Updated: 2015/12/20 10:36:29 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_put_knife(t_env *e)
{
	static int		count = 0;

	if (e->knife == 1)
	{
		if (count <= 25)
			mlx_put_image_to_window(e->mlx, e->win, e->anim[1], e->s_x / 2,\
			e->s_y - 23 - (count * 2));
		if (count > 25 && count <= 50)
			mlx_put_image_to_window(e->mlx, e->win, e->anim[1], e->s_x / 2,\
			e->s_y - 23 - (50 - count) * 2);
		if (count > 50)
		{
			count = 0;
			e->knife = 0;
		}
		count += 4;
	}
	else
		mlx_put_image_to_window(e->mlx, e->win, e->anim[1], e->s_x / 2,\
			e->s_y - 23);
}
