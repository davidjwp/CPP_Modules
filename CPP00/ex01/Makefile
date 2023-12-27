# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/24 14:34:26 by djacobs           #+#    #+#              #
#    Updated: 2023/12/27 15:01:32 by djacobs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= PhoneBook

CC		= c++

CFLAGS	= -g -std=c++98 -Wextra -Werror -Wall

HEADER	= main.hpp Contact.class.hpp PhoneBook.class.hpp 

SRCS	= 	Contact.cpp \
			main.cpp \
			PhoneBook.cpp \

OBJS	= $(SRCS:.cpp=.o)


debug: 
	$(eval CC := g++)

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CC) -c $(CFLAGS) $< -o $@

clean: 
	rm *.o

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: clean re fclean

