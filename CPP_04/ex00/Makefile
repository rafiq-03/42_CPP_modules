# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/14 16:33:55 by rmarzouk          #+#    #+#              #
#    Updated: 2024/12/24 11:10:43 by rmarzouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS= -Wall -Wextra -Werror -std=c++98
CC = c++
NAME= Animal
HEADER=	$(addprefix include/, \
						Dog.hpp \
						Cat.hpp \
						Animal.hpp\
						WrongAnimal.hpp\
						WrongDog.hpp\
						WrongCat.hpp)
SRC= $(addprefix src/, \
						main.cpp \
						Dog.cpp \
						Cat.cpp \
						Animal.cpp\
						WrongAnimal.cpp\
						WrongDog.cpp\
						WrongCat.cpp)
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
	
