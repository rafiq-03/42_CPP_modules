/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:29:13 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/11 16:35:26 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

Animal::Animal(void) : type("Animal")
{
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal Destructor called" << std::endl;
}

Animal::Animal(const Animal& obj)
{
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = obj;
}

Animal& Animal::operator=(const Animal& obj)
{
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if (this != &obj)
		type = obj.type;
	return (*this);
}

void Animal::makeSound() const {
	std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const
{
	return (type);
}
