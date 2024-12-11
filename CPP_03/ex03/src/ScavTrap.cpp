/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:28:53 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/06 11:55:18 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"


/*-[constructors : ]--------------*/

ScavTrap::ScavTrap(){// default constructor

	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	std::cout << "ScavTrap " << _Name << " is alive now :)" << std::endl;
}

ScavTrap::ScavTrap(const std::string& Name)
{
	_Name = Name;
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	std::cout << "ScavTrap " << _Name << " is alive now :)" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &other)
{
	_Name = other.getName();// check it later
	_HitPoints = other.getHit();
	_EnergyPoints = other.getEnergy();
	_AttackDamage = other.getAttack();
	std::cout << "ScavTrap " << _Name << " is alive now, thanks to its copy :)" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this == &other)
		return (*this);
	_Name = other.getName();// check it later
	_HitPoints = other.getHit();
	_EnergyPoints = other.getEnergy();
	_AttackDamage = other.getAttack();
	return (*this);
}

ScavTrap::~ScavTrap(){std::cout << "ScavTrap " << _Name << " is dead :(" << std::endl;}


/*-[getters : ]--------------*/

void ScavTrap::attack(const std::string& target){
	if (!_EnergyPoints || !_HitPoints)
	{
		std::cout << "ScavTrap " << _Name << " can't Attack target" << std::endl;
		return ;
	}
	_EnergyPoints--;
	std::cout << "ScavTrap " << _Name << " attacks " << target << ", causing " << _AttackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _Name << " is now in Gate keeper mode !" << std::endl;
}
