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

int get_map_info(t_game *g, char *line)
{
	char	**words;
	int		w;
	int		h;

	if (ft_strlen(line) < 11 || ft_countwords(line, ' ') < 3)
		return (0);
	words = ft_strsplit(line, ' ');
	if (ft_strcmp(words[0], "Plateau") != 0)
		return (0);
	w = ft_atoi(words[1]);
	h = ft_atoi(words[1]);
	if (w == 0 || h == 0)
		return (0);
	g->map = newmap(w, h);
	return (1);
}

int	valid_line(t_game *g, char **line)
{
	while (**line && **line != ' ')
		(*line)++;
	if (**line == ' ')
		(*line)++;
	else
		return (0);
	if (ft_strlen(*line) != g->map->width)
		return (0);
	return (1);
}
