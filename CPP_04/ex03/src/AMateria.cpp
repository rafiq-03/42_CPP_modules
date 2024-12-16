/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:34:21 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/16 15:18:55 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"

AMateria::AMateria(void){
	// std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type){(void)type;}

AMateria::~AMateria(void){
	// std::cout << "AMateria Destructor called" << std::endl;
}

AMateria::AMateria(const AMateria& obj){(void)obj;
	// std::cout << "AMateria Copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& obj){
	// std::cout << "AMateria Copy assignment operator called" << std::endl;
	(void)obj;
	return (*this);
}

std::string const & AMateria::getType() const{
	return (_Type);
}

void AMateria::use(ICharacter& target){// do it later
	// std::cout << "this is a virtual function" << std::endl;
	(void)target;
}

