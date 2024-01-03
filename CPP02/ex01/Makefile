# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 17:08:21 by djacobs           #+#    #+#              #
#    Updated: 2024/01/03 15:30:56 by djacobs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Fix

CC		= c++

CFLAGS	= -std=c++98 -Wall -Wextra -Werror

HEADER	= Fixed.hpp

SRCS	= Fixed.cpp main.cpp

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