/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:29:59 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/22 10:54:37 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

void	info(std::string stat, ClapTrap &ref)
{
	std::cout << "\n+------------[ " << stat << " ]----------------------\n|" << std::endl;
	std::cout << "| * Type          :  ScavTrap" << std::endl;
	std::cout << "| * Name          :  " << ref.getName() << std::endl;
	std::cout << "| * Hit Points    :  " << ref.getHit() << std::endl;
	std::cout << "| * Energy Points :  " << ref.getEnergy() << std::endl;
	std::cout << "| * Attack Damage :  " << ref.getAttack() << std::endl;
	std::cout << "|\n+------------------------------------------\n" << std::endl;
}


int main(void)
{
	DiamondTrap d("furry");

	info("start", d);
	d.whoAmI();
	for (int i = 0; i < 50; i++)
		d.attack("enemy");
	info("end", d);
	return 0;
}
