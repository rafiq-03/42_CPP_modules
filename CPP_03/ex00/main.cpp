/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:29:59 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/15 16:41:39 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap _3azi("_3azi");

	while (_3azi.getEnergy() && _3azi.getHit())
	{
		std::cout << _3azi.getHit() << std::endl;
		_3azi.attack("lbyad");
		_3azi.beRepaired(12);
	}
	return (0);
}
