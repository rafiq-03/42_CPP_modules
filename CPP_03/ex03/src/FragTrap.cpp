/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:28:53 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/22 18:01:04 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"


/*-[constructors : ]--------------*/

FragTrap::FragTrap(){

	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
	std::cout << "FragTrap " << _Name << " is alive now :)" << std::endl;
}

FragTrap::FragTrap(const std::string& Name)
{
	_Name = Name;
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
	std::cout << "FragTrap " << _Name << " is alive now :)" << std::endl;
}
FragTrap::FragTrap(unsigned int Hit, unsigned int attack)
{
	_HitPoints = Hit;
	_AttackDamage = attack;
}

FragTrap::FragTrap(FragTrap &other)
{
	_Name = other.getName();
	_HitPoints = other.getHit();
	_EnergyPoints = other.getEnergy();
	_AttackDamage = other.getAttack();
	std::cout << "FragTrap " << _Name << " is alive now, thanks to its copy :)" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap Copy assignement operator called" << std::endl;
	if (this == &other)
		return (*this);
	_Name = other.getName();
	_HitPoints = other.getHit();
	_EnergyPoints = other.getEnergy();
	_AttackDamage = other.getAttack();
	return (*this);
}

FragTrap::~FragTrap(){std::cout << "FragTrap " << _Name << " is dead :(" << std::endl;}


/*-[getters : ]--------------*/

void FragTrap::attack(const std::string& target){
	if (!_EnergyPoints || !_HitPoints)
	{
		std::cout << "FragTrap " << _Name << " can't Attack target" << std::endl;
		return ;
	}
	_EnergyPoints--;
	std::cout << "FragTrap " << _Name << " attacks " << target << ", causing " << _AttackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _Name << "Teamwork makes the dream work! High five!" << std::endl;
}
