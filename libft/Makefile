#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/11 12:40:00 by dpetrysh          #+#    #+#              #
#    Updated: 2017/11/11 12:40:05 by dpetrysh         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
SRC := $(wildcard src/*.c)
SRO := $(notdir $(patsubst %.c, %.o, $(SRC)))
VPATH := src includes

all: $(NAME)

$(NAME): $(SRO) libft.h
	ar rc $(NAME) $(SRO)
	ranlib $(NAME)

%.o : %.c
	@gcc -c -I ./includes/ $< -Wall -Wextra -Werror 

clean:
	/bin/rm -f $(SRO)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
