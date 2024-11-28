/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:22:00 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/28 12:18:37 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name (name), _Weapon (NULL){}

HumanB::HumanB(std::string name, Weapon &WeaponB) : _name (name), _Weapon (&WeaponB){}

void	HumanB::setWeapon(Weapon &WeaponB)
{
	_Weapon = &WeaponB;
}
void	HumanB::attack()
{
	if (_Weapon == NULL)
	{
		std::cout << _name << " can't attack  the enemy " << std::endl;
		return;
	}
	std::cout << _name << " attacks with their " << _Weapon->getType() << std::endl;
}
