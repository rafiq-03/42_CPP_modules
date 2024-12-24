/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:34:21 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/24 12:37:38 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"

AMateria::AMateria(void){
	if (D_MODE)
		std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	if (D_MODE)
		std::cout << "AMateria Parametrized constructor called" << std::endl;
	_Type = type;
}

AMateria::~AMateria(void){
	if (D_MODE)
		std::cout << "AMateria Destructor called" << std::endl;
}

AMateria::AMateria(const AMateria& obj){
	if (D_MODE)
		std::cout << "AMateria Copy constructor called" << std::endl;
	(void)obj;
}

AMateria& AMateria::operator=(const AMateria& obj){
	if (D_MODE)
		std::cout << "AMateria Copy assignment operator called" << std::endl;
	(void)obj;
	return (*this);
}

std::string const & AMateria::getType() const{
	return (_Type);
}

void AMateria::use(ICharacter& target){
	std::cout << "Unknoun Materia heal or shoot " << target.getName() << std::endl;
}

