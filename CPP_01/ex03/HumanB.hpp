/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:25:18 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/23 20:37:53 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class	HumanB
{
	private:
		std::string	_name;
		Weapon* 	_Weapon;
	public:
		HumanB(std::string name);
		HumanB(std::string name, Weapon &WeaponB);
		void	setWeapon(Weapon &WeaponB);
		void	attack();
};

#endif
