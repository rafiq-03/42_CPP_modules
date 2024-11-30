/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:29:59 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/30 18:37:15 by rmarzouk         ###   ########.fr       */
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
	// ClapTrap *ptr1 = new ClapTrap("clappy");
	// std::cout << "\n+------------------------------------------" << std::endl;
	// std::cout << "| * Type          :  ClapTrap" << std::endl;
	// std::cout << "| * Name          :  " << ptr1->getName() << std::endl;
	// std::cout << "| * Hit Points    :  " << ptr1->getHit() << std::endl;
	// std::cout << "| * Energy Points :  " << ptr1->getEnergy() << std::endl;
	// std::cout << "| * Attack Damage :  " << ptr1->getAttack() << std::endl;
	// std::cout << "+------------------------------------------\n" << std::endl;
	// for (int i = 12; i >= 0; i--)
	// 	ptr1->attack("enemy1");
	// for (int i = 3; i >= 0; i--)
	// 	ptr1->beRepaired(3);
	// delete ptr1;
	
	std::cout << "\n\n--------------------------------\n" << std::endl;
	
	ClapTrap *ptr2 = new ScavTrap("Scav");
	info("start", *ptr2);
	for (int i = 45; i >= 0; i--)
		ptr2->attack("enemy2");
	for (int i = 3; i >= 0; i--)
		ptr2->beRepaired(6);
	for (int i = 3; i >= 0; i--)
		ptr2->attack("enemy4");
	info("end", *ptr2);
	delete ptr2;

}
