/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:37:13 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/16 11:26:22 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Lists.hpp"

class Character : public ICharacter
{
	private:
		std::string	_Name;
		AMateria*	_Inventory[4];// = new Materia[4] Character has 4 materias
		List		_Materias;// this is a linked list of materias that character doesn't use them
	public:
		Character(void); // Default constructor
		Character(std::string const name); // Parametrized constructor
		Character(const Character& obj); // Copy constructor
		Character&	operator=(const Character& obj); // Copy assigment operator
		~Character(); // Destructor
		
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
