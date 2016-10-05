#include "filler.h"
#include "libft.h"
#include <stdlib.h>

t_game	*newgame(void)
{
	t_game	*g;

	g = (t_game*)malloc(sizeof(t_game));
	g->player = 0;
	g->turn = 0;
	g->map = NULL;
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
	m->grid = (char**)malloc(h * sizeof(char*) + 1);
	while (i < h)
		m->grid[i++] = ft_strnew(w);
	m->grid[i] = NULL;
	return (m);
}
