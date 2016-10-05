# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkejji <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/28 19:33:22 by mkejji            #+#    #+#              #
#    Updated: 2016/09/28 19:44:08 by mkejji           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mkejji.filler

SRC =	src/main.c \
		src/parse.c	\
		src/parseutils.c \
		src/init.c \
		src/utils.c \
		src/test.c

CFLAGS = -Wall -Wextra -Werror

CC = gcc

all:
	make -C libft
	$(CC) -Iinc -Llibft -lft $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm $(NAME)
