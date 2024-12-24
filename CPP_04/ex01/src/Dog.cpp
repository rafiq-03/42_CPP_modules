/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:34:29 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/24 11:19:39 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog Default constructor called" << std::endl;
	type = "Dog";
	_brain = new Brain();
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor called" << std::endl;
	delete _brain;
}

Dog::Dog(const Dog& obj)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	type = obj.type;
	_brain = new Brain(*obj._brain);
}

Dog& Dog::operator=(const Dog& obj)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		type = obj.type;
		delete _brain;
		_brain = new Brain(*obj._brain);
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog: Bark Bark" << std::endl;
}
