/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:56:54 by mkejji            #+#    #+#             */
/*   Updated: 2016/10/06 18:05:41 by mkejji           ###   ########.fr       */
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
	if (!(ft_get_next_line(0, &line)))
		return ((t_game*)freedie(NULL, "STDIN said nothing"));
	g = newgame();
	if (!get_player_info(g, line))
		return ((t_game*)freedie(&g, "Bad player info"));
	ft_strdel(&line);
	return (g);
}

int		read_map(t_game **g)
{
	size_t	i;
	size_t	j;
	char	*line;

	j = 0;
	if (!(ft_get_next_line(0, &line)))
		return ((int)freedie(g, "Bad map info (no map input)"));
	if (!get_map_info(*g, line))
		return ((int)freedie(g, "Bad map info (couldn't get map info)"));
	ft_strdel(&line);
	ft_get_next_line(0, &line);
	ft_strdel(&line);
	while (j < (*g)->map->height && (ft_get_next_line(0, &line)) > 0)
	{
		i = 0;
		if (!valid_map_line(*g, &line))
			return ((int)freedie(g, "Bad map info (unexpected char/length)"));
		while (line[i] && i < (*g)->map->width)
		{
			(*g)->map->grid[j][i] = (char)ft_toupper(line[i]);
			i++;
		}
		j++;
		ft_strdel(&line);
	}
	if (j != (*g)->map->height)
		return ((int)freedie(g, "Bad map info (unexpected height)"));
	return (1);
}

int		read_piece(t_game **g)
{
	size_t	i;
	size_t	j;
	char	*line;

	j = 0;
	if (!(ft_get_next_line(0, &line)))
		return ((int)freedie(g, "Bad piece info (no piece input)"));
	if (!get_piece_info(*g, line))
		return ((int)freedie(g, "Bad piece info (couldn't get piece info)"));
	ft_strdel(&line);
	while (j < (*g)->piece->height && (ft_get_next_line(0, &line)) > 0)
	{
		i = 0;
		if (!valid_piece_line(*g, line))
			return ((int)freedie(g, "Bad piece info (unexpected char/length)"));
		while (line[i] && i < (*g)->piece->width)
		{
			(*g)->piece->grid[j][i] = line[i];
			i++;
		}
		j++;
		ft_strdel(&line);
	}
	if (j != (*g)->piece->height)
		return ((int)freedie(g, "Bad map info (unexpected height)"));
	return (1);
}
