#include "libft.h"
#include "filler.h"
#include <stdlib.h>
#include <unistd.h>

t_game	*init(void)
{
	t_game	*g;
	int		read;
	char	*line;

	line = NULL;
	read = ft_get_next_line(1, &line);
	if (!read)
		return ((t_game*)freedie(NULL, "STDIN said nothing"));
	g = newgame();
	if (!get_player_info(g, line))
		return ((t_game*)freedie(&g, "Bad player info"));
	ft_strdel(&line);
	read = ft_get_next_line(1, &line);
	if (!get_map_info(g, line))
		return ((t_game*)freedie(&g, "Bad map info"));
	return (g);
}

int		read_map(t_game *g)
{
	size_t	i;
	size_t	j;
	char	*line;

	j = 0;
	while((ft_get_next_line(1, &line)) > 0 && j < g->map->height)
	{
		i = 0;
		while (line[i] && line[i] != ' ')
			i++;
		if (ft_strlen(line + i) != g->map->width)
			return ((int)freedie(&g, "Bad map info"));
		while(line[i] && i < g->map->width)
		{
			g->map->grid[j][i] = (char) ft_toupper(line[i]);
			i++;
		}
		if (i != g->map->width)
			return ((int)freedie(&g, "Bad map info"));
		j++;
	}
	if (j != g->map->height)
		return ((int)freedie(&g, "Bad map info"));
	return (1);
}
