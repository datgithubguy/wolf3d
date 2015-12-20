/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 21:30:13 by bal-khan          #+#    #+#             */
/*   Updated: 2015/12/11 21:30:25 by bal-khan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

char	***three_dims(int fd, int size)
{
	char	***assiette;
	char	*buff;
	int		a;
	int		count;

	count = -1;
	if (size <= 0)
		return (NULL);
	assiette = (char***)malloc(sizeof(char**) * (size + 1));
	while ((a = get_next_line(fd, &buff)) > 0)
	{
		assiette[++count] = ft_strsplit(buff, ' ');
		(buff != NULL) ? (free(buff)) : (0);
	}
	assiette[count + 1] = 0;
	return (assiette);
}

int		big(int fd)
{
	int		a;
	int		size;
	char	*line;

	size = 0;
	while ((a = get_next_line(fd, &line)) > 0)
	{
		++size;
		if (ft_strlen(line) == 0)
			return (0);
		free(line);
	}
	return (size);
}
