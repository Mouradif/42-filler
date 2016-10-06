#include "filler.h"
#include "libft.h"
#include <stdlib.h>

void	*freedie(t_game **g, char *s)
{
	if (g != NULL)
	{
		free(*g);
		*g = NULL;
	}
	ft_putendl(s);
	return (NULL);
}
