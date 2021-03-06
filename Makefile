# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkejji <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/28 19:33:22 by mkejji            #+#    #+#              #
#    Updated: 2016/10/08 18:20:05 by mkejji           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mkejji.filler

SRC =	src/main.c \
		src/parse.c	\
		src/parseutils.c \
		src/init.c \
		src/utils.c \
		src/play.c \
		src/test.c

CFLAGS = -Wall -Wextra -Werror

CC = gcc

all: libft
	$(CC) $(CFLAGS) -Iinc -Llibft -lft $(SRC) -o $(NAME)

termux: libft
	$(CC) $(CFLAGS) -Iinc $(SRC) libft/libft.a -o $(NAME)

debug: libft
	$(CC) -g $(CFLAGS) -Iinc -Llibft -lft $(SRC) -o $(NAME)_debug
libft:
	make -C libft

clean:
	rm $(NAME)

.PHONY: libft
