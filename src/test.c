#include "libft.h"
#include "filler.h"

void	print_map(t_game *g)
{
	size_t	j;

	j = 0;
	while (j < g->map->height)
	{
		ft_putendl(g->map->grid[j]);
		j++;
	}
}
