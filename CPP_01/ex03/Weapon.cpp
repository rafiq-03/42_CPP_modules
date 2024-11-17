/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:13:38 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/07 13:39:00 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	// std::cout << "new weapon here" << std::endl;	
}

Weapon::Weapon(std::string _type)
{
	type =_type;	
}
const std::string& Weapon::getType()
{
	return type;
}
void Weapon::setType(std::string _type)
{
	type = _type;
}