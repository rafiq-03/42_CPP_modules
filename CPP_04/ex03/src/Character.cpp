/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:37:15 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/16 15:48:24 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"

Character::Character(void){// to do
	std::cout << "Character Default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_Inventory[i] = NULL;
}

Character::Character(std::string const name){// to do
	std::cout << "Character Parametrized constructor called" << std::endl;
	_Name = name;
	for (int i = 0; i < 4; i++)
		_Inventory[i] = NULL;
}

Character::~Character(void){// to do

	// std::cout << "Character Destructor called" << std::endl;
	// we must destroy any materia here 
	for (int i = 0; i < 4; i++)
		delete _Inventory[i];
}

Character::Character(const Character& obj){// to do
	std::cout << "Character Copy constructor called" << std::endl;
	_Name = obj._Name;
	for (int i = 0; i < 4; i++){
		if (obj._Inventory[i])
			_Inventory[i] = obj._Inventory[i]->clone();// assigne to is another materia
	}
	_Materias = obj._Materias.clone();
	// it still need linked list of player
}

Character& Character::operator=(const Character& obj){// to do
	std::cout << "Character Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		_Name = obj._Name;
		for (int i = 0; i < 4; i++)
		{
			if (obj._Inventory[i])
			{
				delete _Inventory[i];// delete materia
				_Inventory[i] = obj._Inventory[i]->clone();// assigne to is another materia
			}
		}
		_Materias = obj._Materias.clone();
	}
	return (*this);
}

std::string const & Character::getName() const {// done
	return (_Name);
}

void Character::equip(AMateria* m){// to do
	if (m == NULL){
		std::cerr << "Character : Invalid materia" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++){
		if (!_Inventory[i]){
			_Inventory[i] = m;
			return ;
		}
	}
	std::cerr << "Character : inventory is full" << std::endl;
}

void Character::unequip(int idx){// to do
	if (idx < 0 || idx > 3){
		std::cerr << "Character : Can't unequip materia" << std::endl;
		return;
	}
	else if (_Inventory[idx]){
		_Materias.add(_Inventory[idx]);
		_Inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target){// almost done
	// check if the idx is valid then call AMateria use fucntion
	if (idx < 0 || idx > 3)
	{
		std::cerr << "invalid materia's index" << std::endl;
		return ;
	}
	else if (_Inventory[idx])
		_Inventory[idx]->use(target);
}

