/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:29:59 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/22 17:34:26 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	clap("clappy");

	std::cout << "\n+------------------------------------------" << std::endl;
	std::cout << "| * Type          :  ClapTrap" << std::endl;
	std::cout << "| * Name          :  " << clap.getName() << std::endl;
	std::cout << "| * Hit Points    :  " << clap.getHit() << std::endl;
	std::cout << "| * Energy Points :  " << clap.getEnergy() << std::endl;
	std::cout << "| * Attack Damage :  " << clap.getAttack() << std::endl;
	std::cout << "+------------------------------------------\n" << std::endl;
	for(int i=0; i < 7; i++)
		clap.attack("enemy");
	clap.attack("enemy");
	for(int i=0; i < 5; i++)
		clap.beRepaired(2);
	clap.attack("enemy1");
	for (int i = 0; i < 5; i++)
		clap.takeDamage(10);
	return (0);
}
