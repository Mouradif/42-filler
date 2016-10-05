#include "libft.h"
#include "filler.h"
#include <stdlib.h>
#include <unistd.h>

t_game	*init(void)
{
	t_game	*g;
	int		read;
	char	*line;

	g = (t_game*)malloc(sizeof(t_game));
}

int		read_map(t_game *g)
{

	int		i;
	int		j;
char	*line;
	int		len;

	j = 0;
	while((len = ft_get_next_line(1, &line)) > 0 && j < g->height)
	{
		i = 0;
		while (line[i] && line[i] != ' ')
			i++;
		while(line[i] && i < g->map->width)
		{
			g->map->grid[j][i] = (char) ft_toupper(line[i]);
			i++;
		}
		if (i != g->map->width)
			return (ft_freedie(&g, "Bad map info"));
		j++;
	}
	if (j != g->map->height)
		return (ft_freedie(&g, "Bad map info"));
}
