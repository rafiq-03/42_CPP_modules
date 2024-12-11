/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:28:53 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/06 11:55:18 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"


/*-[constructors : ]--------------*/

DiamondTrap::DiamondTrap(): ScavTrap(), FragTrap(){
	_EnergyPoints = 50;
	std::cout << "DiamondTrap " << _Name << " is alive now :)" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& Name): ScavTrap(Name), FragTrap(Name){
	ClapTrap::setName(Name + "_clap_name");
	_Name = Name;
	_EnergyPoints = 50;
	std::cout << "DiamondTrap " << _Name << " is alive now :)" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &other){
	*this = other;
	std::cout << "DiamondTrap " << _Name << " is alive now, thanks to its copy :)" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other){
	if (this == &other)
		return (*this);
	ClapTrap::_Name = ClapTrap::_Name;
	_Name = other._Name;
	_HitPoints = other._HitPoints;
	_EnergyPoints = other._EnergyPoints;
	_AttackDamage = other._AttackDamage;
	return (*this);
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap " << _Name << " is dead :(" << std::endl;
}


/*-[getters : ]--------------*/

void DiamondTrap::attack(const std::string& target){
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(){
	std::cout << "I am " << _Name << " and my ClapTrap name is " << ClapTrap::_Name << std::endl;
}
