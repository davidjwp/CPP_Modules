# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djacobs <djacobs@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 16:15:48 by djacobs           #+#    #+#              #
#    Updated: 2024/02/11 18:16:54 by djacobs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Form

CC		= c++

CFLAGS	= -g3 -std=c++98 -Wall -Werror -Wextra

HEADER	= Form.hpp Bureaucrat.hpp

SRCS	= Form.cpp Bureaucrat.cpp main.cpp

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