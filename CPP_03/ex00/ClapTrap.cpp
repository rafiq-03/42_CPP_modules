/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:28:53 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/15 16:28:06 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


/*-[constructors : ]--------------*/

ClapTrap::ClapTrap():_Name("Unkown"), _HitPoints(10), _EnergyPoints(10) , _AttackDamage (0)
{
	std::cout << "ClapTrap " << _Name << " is alive now :)" << std::endl;
}
ClapTrap::ClapTrap(const std::string& Name):_Name (Name), _HitPoints(10), _EnergyPoints(10) , _AttackDamage (0)
{
	std::cout << "ClapTrap " << _Name << " is alive now :)" << std::endl;
}
ClapTrap::ClapTrap(ClapTrap &other): _Name (other.getName()), _HitPoints(other.getHit()), _EnergyPoints (other.getEnergy()), _AttackDamage(other.getAttack())
{
	std::cout << "ClapTrap " << _Name << " is alive now, thanks to its copy :)" << std::endl;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	_HitPoints = other.getHit();
	_EnergyPoints = other.getEnergy();
	_AttackDamage = other.getAttack();
	return (*this);
}

ClapTrap::~ClapTrap(){std::cout << "ClapTrap " << _Name << " is dead :(" << std::endl;}

/*-[setters : ]--------------*/

void	ClapTrap::setHit(const unsigned int amount){ _HitPoints=amount;}
void	ClapTrap::setEnergy(const unsigned int amount){ _EnergyPoints=amount;}
void	ClapTrap::setAttack(const unsigned int amount){ _AttackDamage=amount;}

/*-[getters : ]--------------*/

std::string	ClapTrap::getName(void) const{return _Name;}
unsigned int ClapTrap::getHit(void) const{return _HitPoints;}
unsigned int ClapTrap::getEnergy(void) const{return _EnergyPoints;}
unsigned int ClapTrap::getAttack(void) const{return _AttackDamage;}

/*-[getters : ]--------------*/

void ClapTrap::attack(const std::string& target){
	if (!_EnergyPoints || !_HitPoints)
	{
		std::cout << "ClapTrap " << _Name << " can't Attack target" << std::endl;
		return ;	
	}
	_EnergyPoints--;
	_AttackDamage++;// check it later
	std::cout << "ClapTrap " << _Name << " attacks " << target << ", causing " << "damage" << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount){
	_HitPoints -= amount;
	std::cout << "ClapTrap " << _Name << " take " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (!_EnergyPoints || !_HitPoints)
	{
		std::cout << "ClapTrap " << _Name << " can't repaire itself !" << std::endl;
		return ;
	}
	_EnergyPoints--;
	_HitPoints += amount;
	std::cout << "ClapTrap " << _Name << " repaire itself " << amount << " of hit points !" << std::endl;
}
