/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:37:13 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/24 13:31:17 by rmarzouk         ###   ########.fr       */
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
		AMateria*	_Inventory[4];
		List		_Materias;
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
