/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:39:38 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/16 14:05:47 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Ice.hpp"

Ice::Ice(void){
	// std::cout << "Ice Default constructor called" << std::endl;
	_Type = "ice";
}

Ice::~Ice(void){
	// std::cout << "Ice Destructor called" << std::endl;
}

Ice::Ice(const Ice& obj){
	// std::cout << "Ice Copy constructor called" << std::endl;
	_Type = obj._Type;
}

Ice& Ice::operator=(const Ice& obj){
	// std::cout << "Ice Copy assignment operator called" << std::endl;
	if (this != &obj)
		_Type = obj._Type;
	return (*this);
}

Ice* Ice::clone() const { // override method from base class AMateria
	return (new Ice(*this));
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at [ " << target.getName() << " ] *" << std::endl;// name will get it later
}
