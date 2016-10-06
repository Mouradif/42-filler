/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 19:37:50 by mkejji            #+#    #+#             */
/*   Updated: 2016/10/06 17:37:16 by mkejji           ###   ########.fr       */
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
	t_map	*piece;
}				t_game;

t_game			*init(void);
int				read_map(t_game **g);
int				read_piece(t_game **g);
int				get_player_info(t_game *g, char *line);
int				get_map_info(t_game *g, char *line);
int				get_piece_info(t_game *g, char *line);
t_game			*newgame(void);
t_map			*newmap(int w, int h);
void			*freedie(t_game **g, char *err);
void			print_map(t_game *g);
int				valid_map_line(t_game *g, char **line);
int				valid_piece_line(t_game *g, char *line);

#endif
