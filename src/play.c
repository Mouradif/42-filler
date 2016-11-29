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

size_t	get_move_score(t_game *g, size_t i, size_t j)
{
	if (g == NULL)
		return (0);
	i = j;
	j = i;
	return (1);
}

void	compare_add_move(t_game *g, size_t i, size_t j)
{
	size_t	score;

	score = get_move_score(g, i, j);
	if (score >= g->move.score)
	{
		g->move.i = i;
		g->move.j = j;
		g->move.score = score;
	}
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
			if ((g->piece->grid[y][x] == '*' && (y + j) >= g->map->height) || ((g->piece->grid[y][x] == '*') && (x + i) >= g->map->width))
				return (0);
			if ((g->piece->grid[y][x] == '*') && (j + y < g->map->height) && (i + x < g->map->width) && ft_isalpha(g->map->grid[j + y][i + x]))
				sect += (ft_toupper(g->map->grid[j + y][i + x]) == g->player) ? 1 : 2;
			if (sect > 1)
				return (0);
			x++;
		}
		y++;
	}
	if (sect == 1)
		compare_add_move(g, i, j);
	return (0);
}

int		print_best_move(t_game *g)
{
	size_t	i;
	size_t	j;
	int		spot;

	g->move.i = 0;
	g->move.j = 0;
	g->move.score = 0;
	if (g->map == NULL && g->piece == NULL)
		return (1);
	j = 0;
	while (j < g->map->height)
	{
		i = 0;
		while (i < g->map->width)
		{
			spot = test_spot(g, i, j);
			i++;
		}
		j++;
	}
	print_spot(g->move.i, g->move.j);
	return (g->move.score);
}
