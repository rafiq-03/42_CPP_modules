/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:04:24 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/24 13:23:14 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MateriaSource.hpp"

MateriaSource::MateriaSource(void){
	if (D_MODE)
		std::cout << "MateriaSource Default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_Inventory[i] = NULL;
}

MateriaSource::~MateriaSource(void){
	if (D_MODE)
		std::cout << "MateriaSource Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		delete _Inventory[i];
}

MateriaSource::MateriaSource(const MateriaSource& obj){
	if (D_MODE)
		std::cout << "MateriaSource Copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (obj._Inventory[i])
			this->_Inventory[i] = obj._Inventory[i]->clone();
		else
			this->_Inventory[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj){
	if (D_MODE)
		std::cout << "MateriaSource Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		for (int i = 0; i < 4; i++)
		{
			delete _Inventory[i];
			this->_Inventory[i] = obj._Inventory[i]->clone();
		}
	}
	return (*this);
}


void MateriaSource::learnMateria(AMateria*  m){
	if (!m){
		std::cerr << "MateriaSource : Invalid materia" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++){
		if (_Inventory[i] == NULL){
			_Inventory[i] = m;
			return;
		}
	}
	std::cerr << "MateriaSource : inventory is full" << std::endl; 
}

AMateria* MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < 4; i++){
		if (_Inventory[i] && _Inventory[i]->getType() == type){
			return (_Inventory[i]->clone());
		}
	}
	std::cerr << "MateriaSource : Invalid materia" << std::endl; 
	return (0);
}