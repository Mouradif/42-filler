/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 16:47:54 by mkejji            #+#    #+#             */
/*   Updated: 2016/10/06 16:47:55 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ft_putendl_fd(s, 2);
	return (NULL);
}
