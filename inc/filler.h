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

typedef struct	s_move
{
	size_t	i;
	size_t	j;
	int		score;
}				t_move;

typedef struct	s_game
{
	char	player;
	size_t	turn;
	t_map	*map;
	t_map	*piece;
	t_move	move;
}				t_game;

t_game			*init(void);
int				read_map(t_game **g);
int				read_piece(t_game **g);
int				get_player_info(t_game *g, char *line);
int				get_map_info(t_game *g, char *line);
int				get_piece_info(t_game *g, char *line);
t_game			*newgame(void);
t_map			*newmap(int w, int h);
t_move			newmove(size_t i, size_t j, size_t score);
void			*freedie(t_game **g, char *err);
void			print_map(t_game *g);
int				valid_map_line(t_game *g, char **line);
int				valid_piece_line(t_game *g, char *line);
int				print_best_move(t_game *g);
void			*freegame(t_game **g);
void			*freemap(t_map **m);

#endif
