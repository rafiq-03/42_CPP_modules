/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:29:10 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/21 13:30:57 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:

		std::string	  _Name;
		int  _HitPoints;
		int  _EnergyPoints;
		int  _AttackDamage;

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
		void	setHit(const int amount);
		void	setEnergy(const int amount);
		void	setAttack(const int amount);
		
		/*--------[getters :]-----------------*/
		
		std::string  getName(void)const;
		int getHit(void) const;
		int getEnergy(void) const;
		int getAttack(void) const;

		/*--------[methodes :]-----------------*/
		
		virtual void attack(const std::string& target);
		void takeDamage(int amount);
		void beRepaired(int amount);
};



#endif
