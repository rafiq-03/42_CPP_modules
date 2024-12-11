/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:29:10 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/11 12:50:22 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:

		/*--------[constructors :]-----------------*/
		
		ScavTrap();// default
		ScavTrap(const std::string& Name);// parametrized
		ScavTrap(ScavTrap &other); // copy constructor

		ScavTrap &operator=(const ScavTrap &other);// copy assignement operator
	
		/*--------[destructor :]-----------------*/
		
		~ScavTrap();// destructor

		/*--------[methodes :]-----------------*/
		
		void attack(const std::string& target);
		void guardGate();
};



#endif
