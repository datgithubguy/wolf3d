/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letters_to_tex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 10:36:06 by bal-khan          #+#    #+#             */
/*   Updated: 2015/12/20 10:36:10 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ma_bite(t_env *e, int c)
{
	static int	ox = 0;
	static int	off_y = 0;
	int			x;
	int			y;

	x = -1;
	if (off_y >= 3 * e->sprite_sy / 5 && ox >= e->sprite_sx - e->sprite_sx / 6)
	{
		off_y = 0;
		ox = 0;
		ft_bzero(e->tex, 4 * e->sprite_sx + e->size_line_sprt * e->sprite_sy);
	}
	if (ox >= e->sprite_sx - e->sprite_sx / 6)
	{
		ox = 0;
		off_y += (off_y <= 3 * e->sprite_sy / 5) ? (e->sprite_sy / 5) : (0);
	}
	while (++x < e->sprite_sx / 6 && (y = -1))
	{
		while (++y < e->sprite_sy / 5)
			e->tex[(x + ox) * 4 + e->size_line_sprt * (y + off_y)] =\
		e->alphab[(x + ((c - 1) % 6) * (e->sprite_sx / 6)) * 4 +\
			e->size_line_sprt * (y + ((c - 1) / 6) * e->sprite_sy / 5)];
	}
	ox += e->sprite_sx / 6;
}

int		fun_key(int key)
{
	int	ret;

	ret = 0;
	ret = fun_key_norme(key);
	(key == 0) ? (ret = 1) : (0);
	(key == 1) ? (ret = 19) : (0);
	(key == 2) ? (ret = 4) : (0);
	(key == 3) ? (ret = 6) : (0);
	(key == 4) ? (ret = 8) : (0);
	(key == 5) ? (ret = 7) : (0);
	(key == 6) ? (ret = 28) : (0);
	(key == 7) ? (ret = 24) : (0);
	(key == 8) ? (ret = 3) : (0);
	(key == 9) ? (ret = 22) : (0);
	(key == 38) ? (ret = 10) : (0);
	(key == 40) ? (ret = 11) : (0);
	(key == 37) ? (ret = 12) : (0);
	(key == 11) ? (ret = 2) : (0);
	(key == 45) ? (ret = 14) : (0);
	(key == 46) ? (ret = 13) : (0);
	return (ret);
}

int		fun_key_norme(int key)
{
	int	ret;

	ret = 0;
	(key == 12) ? (ret = 17) : (0);
	(key == 13) ? (ret = 23) : (0);
	(key == 14) ? (ret = 5) : (0);
	(key == 15) ? (ret = 18) : (0);
	(key == 16) ? (ret = 27) : (0);
	(key == 17) ? (ret = 20) : (0);
	(key == 32) ? (ret = 21) : (0);
	(key == 34) ? (ret = 9) : (0);
	(key == 31) ? (ret = 15) : (0);
	(key == 35) ? (ret = 16) : (0);
	return (ret);
}
