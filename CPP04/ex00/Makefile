# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 16:15:48 by djacobs           #+#    #+#              #
#    Updated: 2024/01/07 13:19:04 by djacobs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Animal

CC		= c++

CFLAGS	= -g3 -std=c++98 -Wall -Werror -Wextra

HEADER	= Animal.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp Cat.hpp

SRCS	= Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp main.cpp

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