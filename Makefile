#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/06 17:14:10 by dpetrysh          #+#    #+#              #
#    Updated: 2018/03/06 17:14:11 by dpetrysh         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = amain

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src/
LIB_DIR = ./libft/

_SRC = main.c \
		checker.c \
		utility.c \
		ht_make.c \
		emancipator.c \
		room_checker.c \
		errors.c \
		printer.c \
		adj_list.c \
		bfs.c \
		queue.c

SRC = $(_SRC:%.c=$(SRC_DIR)%.c)$
OBJ = $(_SRC:%.c=%.o)$

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) 
	make -C $(LIB_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L$(LIB_DIR) -lft -g

%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -I ./libft -c $< -o $@

clean: 
	make -C $(LIB_DIR) clean
	/bin/rm -rf $(OBJ)

fclean: clean
	make -C $(LIB_DIR) fclean
	/bin/rm -rf $(NAME)

re: fclean all
