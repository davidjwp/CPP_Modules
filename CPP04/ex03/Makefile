# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 16:15:48 by djacobs           #+#    #+#              #
#    Updated: 2024/01/12 16:45:59 by djacobs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Materia

CC		= c++

CFLAGS	= -g3 -std=c++98 -Wall -Werror -Wextra

HEADER	= AMateria.hpp Character.hpp Cure.hpp Ice.hpp \
		  ICharacter.hpp IMateriaSource.hpp MateriaSource.hpp

SRCS	= Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp main.cpp \
		  AMateria.cpp

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