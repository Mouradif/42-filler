#include "filler.h"
#include "libft.h"
#include <stdlib.h>

void	*freedie(t_game **g, char *s)
{
	free(*g);
	ft_putendl(s);
	return (NULL);
}
