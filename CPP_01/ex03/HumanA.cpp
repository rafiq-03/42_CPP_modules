/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:22:00 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/28 12:19:10 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &WeaponA): _name(name), _Weapon(WeaponA){}

void	HumanA::attack()
{
	std::cout << _name << " attacks with their " << _Weapon.getType() << std::endl;
}
