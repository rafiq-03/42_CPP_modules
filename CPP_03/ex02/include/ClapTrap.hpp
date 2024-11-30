/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:29:10 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/30 18:14:12 by rmarzouk         ###   ########.fr       */
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
		ClapTrap();// default
		ClapTrap(const std::string& Name);// parametrized
		ClapTrap(ClapTrap &other); // copy constructor

		ClapTrap &operator=(const ClapTrap &other);// copy assignement operator
	
		/*--------[destructor :]-----------------*/
		
		virtual ~ClapTrap();// destructor
		
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
		
		virtual void attack(const std::string& target);// we want stravtrap to make its own attack methode so we make this virtual
		void takeDamage(int amount);
		void beRepaired(int amount);
};



#endif
