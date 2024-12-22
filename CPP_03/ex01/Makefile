# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/14 16:33:55 by rmarzouk          #+#    #+#              #
#    Updated: 2024/12/22 10:38:57 by rmarzouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS= -Wall -Wextra -Werror -std=c++98
CC = c++
NAME= ScavTrap
HEADER= $(addprefix include/, \
						ClapTrap.hpp\
						ScavTrap.hpp )
SRC= $(addprefix src/, \
						main.cpp \
						ClapTrap.cpp \
						ScavTrap.cpp )

OBJ=$(SRC:.cpp=.o)

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
fclean:clean
	rm -rf $(NAME)
re:
	@make fclean
	@make all
	
