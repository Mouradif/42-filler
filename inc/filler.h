/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 19:37:50 by mkejji            #+#    #+#             */
/*   Updated: 2016/09/28 19:40:53 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <stdlib.h>

typedef struct	s_map
{
	size_t	width;
	size_t	height;
	char	**grid;
}				t_map;

typedef struct	s_game
{
	char	player;
	size_t	turn;
	t_map	*map;
}				t_game;

#endif
