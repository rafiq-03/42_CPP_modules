# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/14 16:33:55 by rmarzouk          #+#    #+#              #
#    Updated: 2025/01/25 16:34:34 by rmarzouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS= -Wall -Wextra -Werror -std=c++98 #-fsanitize=address
CC = c++
NAME= Bureaucrat
HEADER=	$(addprefix include/, \
							Bureaucrat.hpp\
							AForm.hpp\
							PresidentialPardonForm.hpp\
							RobotomyRequestForm.hpp \
							ShrubberyCreationForm.hpp)
SRC= $(addprefix src/, \
					main.cpp\
					Bureaucrat.cpp\
					AForm.cpp\
					PresidentialPardonForm.cpp\
					RobotomyRequestForm.cpp\
					ShrubberyCreationForm.cpp)
OBJ=$(SRC:.cpp=.o)

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	# rm target_shrubbery
fclean:clean
	rm -rf $(NAME)
re:
	@make fclean
	@make all
	
