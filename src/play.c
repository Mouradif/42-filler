#include "filler.h"
#include "libft.h"
#include <stdlib.h>

int		print_best_move(t_game *g)
{
	freemap(&(g->piece));
	ft_putstr("0 0\n");
	return (1);
}
