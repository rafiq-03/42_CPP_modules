/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:29:59 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/21 17:08:22 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

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
	ClapTrap *ptr = new ScavTrap("Scav");
	info("start", *ptr);
	for (int i = 45; i >= 0; i--)
		ptr->attack("enemy2");
	for (int i = 3; i >= 0; i--)
		ptr->beRepaired(6);
	for (int i = 3; i >= 0; i--)
		ptr->attack("enemy4");
	info("end", *ptr);
	delete ptr;
}
