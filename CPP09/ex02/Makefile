# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 07:05:56 by davidjwp          #+#    #+#              #
#    Updated: 2024/04/24 17:37:42 by djacobs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= PmergeMe

CC		= c++

CFLAGS	= -g -std=c++98 -Wextra -Werror -Wall 

HEADERS	= PmergeMe.hpp 

SRCS	= main.cpp PmergeMe.cpp

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
