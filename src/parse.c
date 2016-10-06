/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:56:54 by mkejji            #+#    #+#             */
/*   Updated: 2016/10/06 16:24:26 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

t_game	*init(void)
{
	t_game	*g;
	char	*line;

	line = NULL;
	if (!(ft_get_next_line(STDIN_FILENO, &line)))
		return ((t_game*)freedie(NULL, "STDIN said nothing"));
	g = newgame();
	if (!get_player_info(g, line))
		return ((t_game*)freedie(&g, "Bad player info"));
	ft_strdel(&line);
	read_map(&g);
	return (g);
}

int		read_map(t_game **g)
{
	size_t	i;
	size_t	j;
	char	*line;

	j = 0;
	if (!(ft_get_next_line(STDIN_FILENO, &line)))
		return ((int)freedie(g, "Bad map info (no map input)"));
	if (!get_map_info(*g, line))
		return ((int)freedie(g, "Bad map info (couldn't get map info)"));
	ft_get_next_line(STDIN_FILENO, &line);
	while((ft_get_next_line(STDIN_FILENO, &line)) > 0 && j < (*g)->map->height)
	{
		i = 0;
		if (!valid_line(*g, &line))
			return ((int)freedie(g, "Bad map info (unexpected char or length)"));
		while(line[i] && i < (*g)->map->width)
		{
			(*g)->map->grid[j][i] = (char) ft_toupper(line[i]);
			i++;
		}
		j++;
	}
	if (j != (*g)->map->height)
		return ((int)freedie(g, "Bad map info (unexpected height)"));
	return (1);
}
