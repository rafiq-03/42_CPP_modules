# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/14 16:33:55 by rmarzouk          #+#    #+#              #
#    Updated: 2024/11/25 11:14:25 by rmarzouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS= -Wall -Wextra -Werror -std=c++98
CC = c++
HEADERS=PhoneBook.hpp Contact.hpp
NAME=PhoneBook
SRC= main.cpp PhoneBook.cpp Contact.cpp
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
