# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 07:05:56 by davidjwp          #+#    #+#              #
#    Updated: 2024/03/13 00:26:38 by djacobs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= btc

CC		= g++

CFLAGS	= -g -std=c++98 -Wextra -Werror -Wall 

HEADERS	= EC.hpp Convert.hpp

SRCS	= main.cpp Convert.cpp

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

.PHONY: re clean fclean
