/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 19:36:30 by mkejji            #+#    #+#             */
/*   Updated: 2016/10/06 17:38:18 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "filler.h"
#include <stdio.h>

int	main(void)
{
	t_game	*g;

	g = init();
	if (g == NULL)
	{
		puts("ERR game");
		return (1);
	}
	if (!read_map(&g))
	{
			puts("ERR map");
			return (1);
	}
	if (!read_piece(&g))
	{
			puts("ERR piece");
			return (1);
	}
	while (print_best_move(g))
	{
		freemap(&(g->piece));
		freemap(&(g->map));
		if (!read_map(&g))
		{
			puts("ERR map");
			return (1);
		}
		if (!read_piece(&g))
		{
			puts("ERR piece");
			return (1);
		}
	}
	freegame(&g);
	return (0);
}
