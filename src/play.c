#include "filler.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	print_spot(size_t i, size_t j)
{
	ft_putnbr(j);
	ft_putchar(' ');
	ft_putnbr(i);
	ft_putchar('\n');
}

int		test_spot(t_game *g, size_t i, size_t j)
{
	size_t	sect;
	size_t	y;
	size_t	x;

	sect = 0;
	y = 0;
	while (y < g->piece->height)
	{
		x = 0;
		while (x < g->piece->width)
		{
			if (g->piece->grid[y][x] == '*' && (y + j) >= g->map->width)
				return (2);
			if ((g->piece->grid[y][x] == '*') && (x + i) >= g->map->width)
				return (2);
			if ((g->piece->grid[y][x] == '*') && ft_isalpha(g->map->grid[j + y][i + x]))
				sect += (g->map->grid[j + y][i + x] == g->player) ? 1 : 2;
			x++;
		}
		y++;
	}
	if (sect == 1)
	{
		print_spot(i, j);
		return (1);
	}
	return (0);
}

int		print_best_move(t_game *g)
{
	size_t	i;
	size_t	j;
	int		spot;

	if (g->map == NULL && g->piece == NULL)
		return (1);
	j = 0;
	while (j < g->map->height)
	{
		i = 0;
		while (i < g->map->width)
		{
			spot = test_spot(g, i, j);
			if (spot == 1)
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}
