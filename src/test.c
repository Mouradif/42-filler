/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 16:47:52 by mkejji            #+#    #+#             */
/*   Updated: 2016/10/06 17:37:32 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

void	print_map(t_game *g)
{
	size_t	j;

	ft_putstr("Player : ");
	ft_putchar(g->player);
	ft_putchar('\n');
	if (g->map != NULL)
	{
		j = 0;
		while (j < g->map->height)
		{
			ft_putendl(g->map->grid[j]);
			j++;
		}
	}
	if (g->piece != NULL)
	{
		j = 0;
		while (j < g->piece->height)
		{
			ft_putendl(g->piece->grid[j]);
			j++;
		}
	}
}
