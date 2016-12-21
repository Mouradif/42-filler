#include "filler.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#ifndef MIN
# define MIN(a,b) (a > b) ? b : a
#endif
#ifndef MAX
# define MAX(a,b) (a < b) ? b : a
#endif
#ifndef ABS
# define ABS(a) ((a < 0) ? -a : a)
#endif

int		is_safe(t_game *g, size_t x, size_t y, size_t radius)
{
	size_t	xs[2];
	size_t	ys[2];
	char	c;

	ys[0] = (radius > y) ? 0 : y - radius;
	ys[1] = MIN(g->map->height - 1, y + radius);
	if (radius + x > g->map->width || radius + y > g->map->height)
		return (0);
	while (ys[0] <= ys[1])
	{
		xs[0] = (radius > x) ? 0 : x - radius;
		xs[1] = MIN(g->map->width - 1, x + radius);
		while (xs[0] <= xs[1])
		{
			c = g->map->grid[ys[0]][xs[0]];
			if (ft_isalpha(c) && ft_toupper(c) != g->player)
				return (0);
			xs[0] += 1;
		}
		ys[0] += 1;
	}
	return (1);
}

size_t	safe_zone(t_game *g, size_t x, size_t y)
{
	size_t	radius;

	radius = 1;
	while (is_safe(g, x, y, radius))
		radius++;
	return (radius);
}

void	print_spot(size_t i, size_t j)
{
	ft_putnbr(j);
	ft_putchar(' ');
	ft_putnbr(i);
	ft_putchar('\n');
}

size_t	get_move_score(t_game *g, size_t i, size_t j)
{
	int	score;

	score = (0 - safe_zone(g, i, j));
	return (score);
}

void	compare_add_move(t_game *g, size_t i, size_t j)
{
	int	score;

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

	g->move.i = 0;
	g->move.j = 0;
	g->move.score = INT_MIN;
	if (g->map == NULL && g->piece == NULL)
		return (1);
	j = 0;
	while (j < g->map->height)
	{
		i = 0;
		while (i < g->map->width)
			test_spot(g, i++, j);
		j++;
	}
	print_spot(g->move.i, g->move.j);
	return (1);
}
