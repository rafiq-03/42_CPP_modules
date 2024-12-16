/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:04:24 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/16 15:49:20 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MateriaSource.hpp"

MateriaSource::MateriaSource(void){
	// std::cout << "MateriaSource Default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_Inventory[i] = NULL;
}

MateriaSource::~MateriaSource(void){
	// std::cout << "MateriaSource Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		delete _Inventory[i];
}

MateriaSource::MateriaSource(const MateriaSource& obj){
	// std::cout << "MateriaSource Copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_Inventory[i] = obj._Inventory[i]->clone();// deep copy of materiasource
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj){
	// std::cout << "MateriaSource Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		for (int i = 0; i < 4; i++)
		{
			delete _Inventory[i];// delete materia
			this->_Inventory[i] = obj._Inventory[i]->clone();// assigne to is another materia
		}
	}
	return (*this);
}


void MateriaSource::learnMateria(AMateria*  m){ // from abstract class
	if (!m){
		std::cerr << "MateriaSource : Invalid materia" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++){
		if (_Inventory[i] == NULL){
			_Inventory[i] = m;// stor m to materiaSource inventory
			return;
		}
	}
	std::cerr << "MateriaSource : inventory is full" << std::endl; 
}

AMateria* MateriaSource::createMateria(std::string const & type){// from abstract class
	for (int i = 0; i < 4; i++){
		if (_Inventory[i] && _Inventory[i]->getType() == type){
			return (_Inventory[i]->clone());// return copy of this Materia
		}
	}
	std::cerr << "MateriaSource : Invalid materia" << std::endl; 
	return (0);
}