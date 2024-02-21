# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davidjwp <davidjwp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 16:15:48 by djacobs           #+#    #+#              #
#    Updated: 2024/02/20 18:32:01 by davidjwp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= templates

CC		= g++

CFLAGS	= -g -std=c++98 -Wall -Werror -Wextra 

HEADER	= whatever.hpp 

SRCS	= main.cpp 

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