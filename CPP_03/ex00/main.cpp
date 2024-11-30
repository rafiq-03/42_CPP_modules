/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:29:59 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/30 17:59:30 by rmarzouk         ###   ########.fr       */
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
	while (clap.getHit() > 0)
		clap.takeDamage(10);
	return (0);
}
