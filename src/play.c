#include "filler.h"
#include "libft.h"
#include <stdlib.h>

int		print_best_move(t_game *g)
{
	size_t	i;
	size_t	j;
	size_t	x;
	size_t	y;
	size_t	sect;

	j = 0;
	while (j < g->map->height)
	{
		i = 0;
		while (i < g->map->width)
		{
			sect = 0;
			y = 0;
			while (y < g->piece->height && y + j < g->map->height)
			{
				x = 0;
				while (x < g->piece->width && x + i < g->map->width)
				{
					if (ft_isascii(g->map->grid[j + y][i + x]) && g->piece->grid[y][x] == '*')
						sect++;
					x++;
				}
				y++;
			}
			if (sect == 1)
			{
				ft_putnbr(i);
				ft_putchar(' ');
				ft_putnbr(j);
				ft_putchar('\n');
				return (1);
			}
			i++;
		}
		j++;
	}
	freemap(&(g->piece));
	return (0);
}
