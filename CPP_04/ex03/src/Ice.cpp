/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:39:38 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/24 12:08:23 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Ice.hpp"

Ice::Ice(void){
	if (D_MODE)
		std::cout << "Ice Default constructor called" << std::endl;
	_Type = "ice";
}

Ice::~Ice(void){
	if (D_MODE)
		std::cout << "Ice Destructor called" << std::endl;
}

Ice::Ice(const Ice& obj){
	if (D_MODE)
		std::cout << "Ice Copy constructor called" << std::endl;
	_Type = obj._Type;
}

Ice& Ice::operator=(const Ice& obj){
	if (D_MODE)
		std::cout << "Ice Copy assignment operator called" << std::endl;
	if (this != &obj)
		_Type = obj._Type;
	return (*this);
}

Ice* Ice::clone() const {
	return (new Ice(*this));
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at [ " << target.getName() << " ] *" << std::endl;
}
