/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 16:47:49 by mkejji            #+#    #+#             */
/*   Updated: 2016/10/06 18:01:20 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	get_player_info(t_game *g, char *line)
{
	char	**words;

	if (ft_strlen(line) < 12 || ft_countwords(line, ' ') < 3)
		return (0);
	words = ft_strsplit(line, ' ');
	if (ft_strcmp(words[0], "$$$") != 0)
		return (0);
	if (ft_strcmp(words[1], "exec") != 0)
		return (0);
	if (words[2][0] != 'p')
		return (0);
	if (words[2][1] != '1' && words[2][1] != '2')
		return (0);
	g->player = (words[2][1] == '1') ? 'o' : 'x';
	return (1);
}

int	get_map_info(t_game *g, char *line)
{
	char	**words;
	int		w;
	int		h;

	if (ft_strlen(line) < 11 || ft_countwords(line, ' ') < 3)
		return (0);
	words = ft_strsplit(line, ' ');
	if (ft_strcmp(words[0], "Plateau") != 0)
		return (0);
	h = ft_atoi(words[1]);
	w = ft_atoi(words[2]);
	if (w == 0 || h == 0)
		return (0);
	g->map = newmap(w, h);
	return (1);
}

int	get_piece_info(t_game *g, char *line)
{
	char	**words;
	int		w;
	int		h;

	if (ft_strlen(line) < 9 || ft_countwords(line, ' ') < 3)
		return (0);
	words = ft_strsplit(line, ' ');
	if (ft_strcmp(words[0], "Piece") != 0)
		return (0);
	h = ft_atoi(words[1]);
	w = ft_atoi(words[2]);
	if (w == 0 || h == 0)
		return (0);
	g->piece = newmap(w, h);
	return (1);
}

int	valid_map_line(t_game *g, char **line)
{
	size_t	i;
	char	c;
	char	*newline;

	i = 0;
	while ((*line)[i] <= '9' && (*line)[i] >= '0')
		i++;
	if ((*line)[i] == ' ')
		i++;
	else
		return (0);
	newline = ft_strdup(*line + i);
	ft_strdel(line);
	*line = newline;
	i = 0;
	while ((*line)[i])
	{
		c = ft_toupper((*line)[i]);
		if (c != '.' && c != 'O' && c != 'X')
			return (0);
		i++;
	}
	if (i != g->map->width)
		return (0);
	return (1);
}

int	valid_piece_line(t_game *g, char *line)
{
	size_t	i;

	i = 0;
	if (line == NULL)
		return (0);
	while (line[i])
	{
		if (line[i] != '.' && line[i] != '*')
			return (0);
		i++;
	}
	if (i != g->piece->width)
		return (0);
	return (1);
}
