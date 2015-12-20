/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:14:15 by bal-khan          #+#    #+#             */
/*   Updated: 2015/12/04 04:43:01 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		main(int ac, char **av)
{
	t_env	e;

	(void)ac;
	(void)av;
	e = init_mlx(1000, 500);
	init_env(&e);
	e.map = ft_give_map();
	e.s = 1;
//	mlx_do_key_autorepeaton(e.mlx);
	mlx_hook(e.win, 2, 1L << 0, key_hook, &e);
	mlx_hook(e.win, 3, 1L << 1, magic, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop_hook(e.mlx, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}

int		expose_hook(t_env *e)
{
	static time_t	t1;
	static int		n = 0;

	(t1 == 0) ? (t1 = time(NULL)) : (0);
	if (e && !e->acceuil)
	{
		mlx_clear_window(e->mlx, e->win);
		ft_hello(e);
	}
	else
	{
		mlx_clear_window(e->mlx, e->win);
		ft_bzero(e->data, e->s_x * e->s_y * 4);
		draw(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		ft_put_knife(e);
	}
	if (!(time(NULL) - t1))
		++n;
	((time(NULL) - t1)) ? (e->fps = n) : (0);
	((time(NULL) - t1)) ? (n = 0) : (0);
	((time(NULL) - t1)) ? (t1 = 0) : (0);
	return (1);
}

void	get_pos(double x, double y, t_env *e, int flagg)
{
	static double	oldx;
	static double	oldy;
	static int		darkness;

	if (!flagg)
	{
		e->pos_player_x = oldx;
		e->pos_player_y = oldy;
		e->darkness = darkness;
	}
	if (flagg == 1)
	{
		oldx = x;
		oldy = y;
	}
	if (flagg == 2)
	{
		darkness = e->darkness;
	}
}

int		magic(int key, t_env *e)
{
	if ((key == 125) && e->acceuil)
		e->mooved = 0;
	if ((key == 126) && e->acceuil)
		e->mooveu = 0;
	if (key == 124 && e->acceuil)
		e->rotr = 0;
	if ((key == 123) && e->acceuil)
		e->rotl = 0;
	return (0);
}

int		key_hook(int key, t_env *e)
{
	if (key == 49 && e->knife == 0)
	{
		e->knife = 1;
		system("afplay knife.wav -t 0.5 &");
	}
	if (key == 53)
		ft_exit(0, e);
	if ((key == 125) && e->acceuil)
		e->mooved = 1;
	if ((key == 126) && e->acceuil)
		e->mooveu = 1;
	if (key == 124 && e->acceuil)
		e->rotr = 1;
	if ((key == 123) && e->acceuil)
		e->rotl = 1;
	ft_menu(e, key);
	ft_modes(e, key);
	ft_moove(e, key);
	ft_rotat(e, key);
	if (fun_key(key))
		ma_bite(e, fun_key(key));
	return (0);
}
