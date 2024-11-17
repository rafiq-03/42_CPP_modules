/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:29:10 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/15 16:17:03 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:

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
		
		~ClapTrap();
		
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

		
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};



#endif
