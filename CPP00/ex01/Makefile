# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davidjwp <davidjwp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/24 14:34:26 by djacobs           #+#    #+#              #
#    Updated: 2023/12/25 15:30:29 by davidjwp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= PhoneBook

CC		= c++

CFLAGS	= -g3 -std=c++98 -Wextra -Werror -Wall

HEADER	= PhoneBook.class.hpp Contact.class.hpp

SRCS	= 	PhoneBook.cpp \
			Contact.cpp \
			main.cpp \

OBJS	= $(SRCS:.cpp=.o)

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

