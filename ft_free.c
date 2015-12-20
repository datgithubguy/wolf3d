/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 21:30:01 by bal-khan          #+#    #+#             */
/*   Updated: 2015/12/11 21:30:04 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_exit(int ret, t_env *e)
{
	system("killall afplay");
	mlx_destroy_image(e->mlx, e->img);
	mlx_destroy_window(e->mlx, e->win);
	free_knife(e);
	free_map(e);
	free(e->mlx);
	exit(ret);
}

void	free_knife(t_env *e)
{
	int	a;

	a = -1;
	while (++a <= 3)
	{
		mlx_destroy_image(e->mlx, e->anim[a]);
	}
}

void	free_map(t_env *e)
{
	int	a;
	int	b;

	a = -1;
	b = -1;
	if (!e->map)
		return ;
	while (a < 27 && e->map[++a])
	{
		while (e->map[a][++b])
		{
			free(e->map[a][b]);
		}
		free(e->map[a]);
		b = -1;
	}
	free(e->map);
}
