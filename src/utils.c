/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 16:47:54 by mkejji            #+#    #+#             */
/*   Updated: 2016/10/06 16:47:55 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <stdlib.h>

void	*freemap(t_map **m)
{
	size_t	j;

	if (*m == NULL)
		return (NULL);
	j = 0;
	while (j < (*m)->height)
		free((*m)->grid[j++]);
	free((*m)->grid);
	free(*m);
	return (*m = NULL);
}

void	*freegame(t_game **g)
{
	if (*g == NULL)
		return (NULL);
	if ((*g)->map != NULL)
		freemap(&((*g)->map));
	if ((*g)->piece != NULL)
		freemap(&((*g)->piece));
	free(*g);
	return (*g = NULL);
}

void	*freedie(t_game **g, char *s)
{
	if (g != NULL)
		freegame(g);
	ft_putendl_fd(s, 2);
	return (NULL);
}
