# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/28 19:51:34 by djacobs           #+#    #+#              #
#    Updated: 2023/12/30 19:20:17 by djacobs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= HarlFilter

CC		= c++

CFLAGS	= -g3 -std=c++98 -Wextra -Werror -Wall

SRCS	=  main.cpp Harl.cpp

HEADER	= Harl.hpp

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
