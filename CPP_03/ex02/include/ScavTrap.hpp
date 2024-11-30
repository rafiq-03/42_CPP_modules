/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:29:10 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/30 16:45:18 by rmarzouk         ###   ########.fr       */
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
