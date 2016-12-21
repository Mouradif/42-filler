/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 19:36:30 by mkejji            #+#    #+#             */
/*   Updated: 2016/10/08 19:27:57 by mkejji           ###   ########.fr       */
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
		return (1);
	if (!read_map(&g))
		return ((int)freegame(&g));
	if (!read_piece(&g))
		return ((int)freegame(&g));
	while (print_best_move(g))
	{
		freemap(&(g->piece));
		freemap(&(g->map));
		if (!read_map(&g))
			return ((int)freegame(&g));
		if (!read_piece(&g))
			return ((int)freegame(&g));
	}
	return ((int)freegame(&g));
}
