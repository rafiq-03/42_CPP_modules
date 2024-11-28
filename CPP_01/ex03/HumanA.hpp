/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:25:18 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/28 12:16:33 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class	HumanA
{
	private:
		std::string	_name; 
		Weapon&		_Weapon;
	public:
		HumanA(std::string name, Weapon &WeaponA);
		void	attack();
};

#endif
