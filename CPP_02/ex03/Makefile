# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/14 16:33:55 by rmarzouk          #+#    #+#              #
#    Updated: 2024/12/09 11:11:27 by rmarzouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS= -Wall -Wextra -Werror -std=c++98
CC = c++
NAME=bsp
HEADERS=Fixed.hpp Point.hpp
SRC= main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJ=$(SRC:.cpp=.o)

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
fclean:clean
	rm -rf $(NAME)
re:
	@make fclean
	@make all
