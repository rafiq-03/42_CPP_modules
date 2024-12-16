/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:56:49 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/14 13:22:40 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat Default constructor called" << std::endl;
	type = "Cat";
	_brain = new Brain();// allocate memory for the _brain
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called" << std::endl;
	delete _brain;
}

Cat::Cat(const Cat& obj)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	type = obj.type;
	_brain = new Brain(*obj._brain);
}

Cat& Cat::operator=(const Cat& obj)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		delete _brain;
		type = obj.type;
		_brain = new Brain(*obj._brain);
	}
	return (*this);
}

void Cat::makeSound() const{
	std::cout << "Cat: Meow Meow" << std::endl;
}