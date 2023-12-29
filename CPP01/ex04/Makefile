# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/28 19:51:34 by djacobs           #+#    #+#              #
#    Updated: 2023/12/29 21:17:36 by djacobs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= rpg

CC		= c++

CFLAGS	= -g3 -std=c++98 -Wextra -Werror -Wall

SRCS	=  main.cpp Replace.cpp

HEADER	= Replace.class.hpp

OBJS	= $(SRCS:.cpp=.o)

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CC) -c $(CFLAGS) $< -o $@

clean: 
	rm -f $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: clean re fclean
