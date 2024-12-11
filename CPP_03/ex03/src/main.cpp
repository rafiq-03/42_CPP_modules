/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:29:59 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/11 13:42:59 by rmarzouk         ###   ########.fr       */
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
	DiamondTrap d("RAFIK");
	DiamondTrap b(d);
	DiamondTrap oper;

	oper = d;

	info("DiamondTrap", d);
	d.whoAmI();
	b.whoAmI();
	oper.whoAmI();
	std::cout << "|\n+------------------------------------------\n" << std::endl;
	ClapTrap *dm = new DiamondTrap("YASSINE");
	dm->attack("YASSINE");
	delete dm;
	std::cout << "|\n+------------------------------------------\n" << std::endl;
	return 0;

}
