/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:34:29 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/24 11:19:10 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog(void)
{
	type = "Dog";
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog& obj)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = obj;
}

Dog& Dog::operator=(const Dog& obj)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &obj)
		type = obj.type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog: Bark Bark" << std::endl;
}
