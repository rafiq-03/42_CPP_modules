/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:22:00 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/07 15:07:01 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::setWeapon(Weapon &WeaponB)
{
	_Weapon = &WeaponB;
}
HumanB::HumanB(std::string name)
{
	_name = name;
}
HumanB::HumanB(std::string name, Weapon &WeaponB) : _name (name), _Weapon (&WeaponB){}
void	HumanB::attack()
{
	std::cout << _name << " attacks with their " << _Weapon->getType() << std::endl;
}
