/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:29:10 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/11 13:47:55 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIMONDTRAP_HPP
#define DIMONDTRAP_HPP

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap , public FragTrap
{
	private:
		std::string _Name;
	public:

		/*--------[constructors :]-----------------*/
		
		DiamondTrap();// default
		DiamondTrap(const std::string& Name);// parametrized
		DiamondTrap(DiamondTrap &other); // copy constructor

		DiamondTrap &operator=(const DiamondTrap &other);// copy assignement operator
	
		/*--------[destructor :]-----------------*/
		
		~DiamondTrap();// destructor

		/*--------[methodes :]-----------------*/
		
		void attack(const std::string& target);
		void whoAmI();
};



#endif
