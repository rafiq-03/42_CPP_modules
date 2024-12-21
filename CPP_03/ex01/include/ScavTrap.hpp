/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:29:10 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/21 13:42:06 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:

		/*--------[constructors :]-----------------*/
		
		ScavTrap();
		ScavTrap(const std::string& Name);
		ScavTrap(ScavTrap &other);

		ScavTrap &operator=(const ScavTrap &other);
	
		/*--------[destructor :]-----------------*/
		
		~ScavTrap();

		/*--------[methodes :]-----------------*/
		
		void attack(const std::string& target);
		void guardGate();
};



#endif
