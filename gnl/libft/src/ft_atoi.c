/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 05:55:34 by bal-khan          #+#    #+#             */
/*   Updated: 2014/11/13 05:06:06 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	else
		return (0);
}

int				ft_atoi(const char *s)
{
	int ret;
	int sign;

	ret = 0;
	sign = 1;
	while (ft_isspace(*s))
	{
		s++;
	}
	if (*s == '-' || *s == '+')
	{
		sign = (*s == '-' ? -1 : 1);
		s++;
	}
	while (ft_isdigit(*s))
	{
		ret = (ret * 10) + (*s - '0');
		s++;
	}
	return (ret * sign);
}
