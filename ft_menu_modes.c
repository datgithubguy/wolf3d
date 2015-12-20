/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu_modes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 21:30:55 by bal-khan          #+#    #+#             */
/*   Updated: 2015/12/11 21:30:57 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_resize(t_env *e)
{
	static int	spooky = -1;

	get_pos(e->pos_player_x, e->pos_player_y, e, 1);
	get_pos(0, 0, e, 2);
	mlx_destroy_image(e->mlx, e->img);
	mlx_destroy_window(e->mlx, e->win);
	free_map(e);
	free_knife(e);
	if (spooky == -1)
		*e = init_mlx(2000, 1000);
	else
		*e = init_mlx(1000, 500);
	e->s = (spooky == -1) ? 2 : 1;
	init_env(e);
	e->pos_menu = 0;
	e->map = ft_give_map();
	get_pos(0, 0, e, 0);
	spooky = -spooky;
	mlx_do_key_autorepeaton(e->mlx);
	mlx_hook(e->win, 2, 1L << 0, key_hook, e);
	mlx_hook(e->win, 3, 1L << 1, magic, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop_hook(e->mlx, expose_hook, e);
	mlx_loop(e->mlx);
}

void	ft_menu(t_env *e, int key)
{
	if (key == 123 && !e->acceuil && e->pos_menu > 0)
		e->pos_menu -= 1;
	if (key == 124 && !e->acceuil && e->pos_menu < 1)
		e->pos_menu += 1;
	if (e->pos_menu == 1 && key == 36)
	{
		ft_resize(e);
	}
}

void	ft_modes(t_env *e, int key)
{
	if (key == 36 && e->pos_menu == 0)
		e->acceuil = 1;
	if (key == 35)
	{
		e->pos_menu = 0;
		e->acceuil = 0;
	}
	if (key == 44 && e->acceuil)
	{
		e->darkness = -e->darkness;
		if (!e->sound)
		{
			system("afplay ReviveUndead.wav &");
			system("afplay Scary.wav &");
		}
		e->sound++;
		if (e->darkness == -1)
		{
			e->sound = 0;
			system("killall afplay");
			system("afplay ReviveHuman.wav &");
		}
	}
}

void	ft_step_sound(t_env *e)
{
	static int n = 1;

	if (n % 30 == 3)
		system("afplay dayum.wav -t 0.2 -v 0.1 &");
	e->x_old = e->pos_player_x;
	e->y_old = e->pos_player_y;
	n++;
}

void	ft_hello(t_env *e)
{
	ft_real_string_put(e, "Welcome, to come back to this menu latter, press p",\
		e->s_x / 4, e->s_y / 4);
	ft_real_string_put(e, "Controls : Move with the arrow keys", e->s_x / 4,\
	e->s_y / 4 + 100);
	ft_real_string_put(e, "Press \'/\' to enter darkness mode",\
	e->s_x / 4 + 110, e->s_y / 4 + 120);
	ft_real_string_put(e, "Press it back to return to normal",\
	e->s_x / 4 + 110, e->s_y / 4 + 140);
	ft_real_string_put(e, "exit with escape",\
	e->s_x / 4 + 110, e->s_y / 4 + 160);
	ft_real_string_put(e, "Press Enter to select the menu elements",\
	e->s_x / 4, e->s_y - e->s_y / 3);
	if (e->pos_menu == 0)
	{
		ft_real_string_put(e, ">", e->s_x / 4 + 40, e->s_y - e->s_y / 4);
		ft_real_string_put(e, "<", e->s_x / 4 + 100, e->s_y - e->s_y / 4);
	}
	ft_real_string_put(e, "Start", e->s_x / 4 + 50, e->s_y - e->s_y / 4);
	if (e->pos_menu == 1)
	{
		ft_real_string_put(e, ">", e->s_x / 4 + 130, e->s_y - e->s_y / 4);
		ft_real_string_put(e, "<", e->s_x / 4 + 300, e->s_y - e->s_y / 4);
	}
	ft_real_string_put(e, "Fullcreen/Resize", e->s_x / 4 + 140,\
	e->s_y - e->s_y / 4);
}
