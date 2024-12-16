# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/14 16:33:55 by rmarzouk          #+#    #+#              #
#    Updated: 2024/12/16 15:28:24 by rmarzouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS= -Wall -Wextra -Werror -std=c++98 #-fsanitize=address
CC = c++
NAME= recap
HEADER=	$(addprefix include/, \
						IMateriaSource.hpp\
						ICharacter.hpp\
						AMateria.hpp\
						MateriaSource.hpp\
						Character.hpp\
						Cure.hpp\
						Ice.hpp)
SRC= $(addprefix src/, \
						ICharacter.cpp\
						MateriaSource.cpp\
						AMateria.cpp\
						Character.cpp\
						Cure.cpp\
						Ice.cpp\
						main.cpp)
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
	
