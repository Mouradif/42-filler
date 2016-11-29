/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 16:47:43 by mkejji            #+#    #+#             */
/*   Updated: 2016/10/06 16:57:12 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <stdlib.h>

t_move	newmove(size_t i, size_t j, size_t score)
{
	t_move	move;

	move.i = i;
	move.j = j;
	move.score = score;
	return (move);
}

t_game	*newgame(void)
{
	t_game	*g;

	g = (t_game*)malloc(sizeof(t_game));
	g->player = 0;
	g->turn = 0;
	g->map = NULL;
	g->piece = NULL;
	g->move = newmove(0, 0, 0);
	return (g);
}

t_map	*newmap(int w, int h)
{
	t_map	*m;
	int		i;

	i = 0;
	m = (t_map*)malloc(sizeof(t_map));
	m->width = w;
	m->height = h;
	m->grid = (char**)malloc((h + 1) * sizeof(char*));
	while (i < h)
	{
		m->grid[i] = ft_strnew(w);
		i++;
	}
	m->grid[i] = NULL;
	return (m);
}
