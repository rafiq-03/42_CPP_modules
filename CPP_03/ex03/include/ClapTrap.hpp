/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:29:10 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/22 17:45:05 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:

		std::string	  _Name;
		unsigned int  _HitPoints;
		unsigned int  _EnergyPoints;
		unsigned int  _AttackDamage;

	public:

		/*--------[constructors :]-----------------*/
		ClapTrap();
		ClapTrap(const std::string& Name);
		ClapTrap(ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
	
		/*--------[destructor :]-----------------*/
		
		virtual ~ClapTrap();
		
		/*--------[setters :]-----------------*/
		
		void	setName(const std::string Name);
		void	setHit(const unsigned int amount);
		void	setEnergy(const unsigned int amount);
		void	setAttack(const unsigned int amount);
		
		/*--------[getters :]-----------------*/
		
		std::string  getName(void)const;
		unsigned int getHit(void) const;
		unsigned int getEnergy(void) const;
		unsigned int getAttack(void) const;

		/*--------[methodes :]-----------------*/
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};



#endif
