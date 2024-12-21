/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:29:10 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/21 14:47:11 by rmarzouk         ###   ########.fr       */
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
		
		DiamondTrap();
		DiamondTrap(const std::string& Name);
		DiamondTrap(DiamondTrap &other);

		DiamondTrap &operator=(const DiamondTrap &other);
	
		/*--------[destructor :]-----------------*/
		
		~DiamondTrap();

		/*--------[methodes :]-----------------*/
		
		void attack(const std::string& target);
		void whoAmI();
};



#endif
