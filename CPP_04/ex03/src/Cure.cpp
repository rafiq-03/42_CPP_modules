/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:39:33 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/16 15:17:55 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cure.hpp"

Cure::Cure(void){
	// std::cout << "Cure Default constructor called" << std::endl;
	_Type = "cure";
}

Cure::~Cure(void){
	// std::cout << "Cure Destructor called" << std::endl;
}

Cure::Cure(const Cure& obj){
	// std::cout << "Cure Copy constructor called" << std::endl;
	_Type = obj._Type;
}

Cure& Cure::operator=(const Cure& obj){
	// std::cout << "Cure Copy assignment operator called" << std::endl;
	if (this != &obj)
		_Type = obj._Type;
	return (*this);
}

Cure* Cure::clone() const {// override method from base class AMateria
	return (new Cure(*this));
}

void Cure::use(ICharacter& target){
	std::cout << "* heals [ " << target.getName() << " ] \'s wounds *" << std::endl;// we must add name of the target caracter
}