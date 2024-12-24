/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:35:36 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/24 11:59:15 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"
#include "../include/ICharacter.hpp"
#include "../include/Character.hpp"
#include "../include/Cure.hpp"
#include "../include/Ice.hpp"
#include "../include/MateriaSource.hpp"
#include "../include/IMateriaSource.hpp"
#include "Lists.cpp"
void	subjectTest(){
	std::cout << "Subject test" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;	
}


void	myTest(){
	std::cout << "My test" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("ElMountahi");
	ICharacter *enemy = new Character("Enemy");
	for (size_t i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
		{
			AMateria* tmp = src->createMateria("ice");
			me->equip(tmp);
		}
		else 
		{
			AMateria* tmp = src->createMateria("cure");
			me->equip(tmp);
		}
	}
	AMateria* tmp = src->createMateria("ice");
	me->equip(tmp);
	me->use(0, *enemy);
	me->use(1, *enemy);
	me->unequip(0);
	me->unequip(1);
	me->use(1, *enemy);
	delete src;
	delete me;
	delete enemy;
	delete tmp;
}

int main(void)
{
	subjectTest();
	myTest();
	system("leaks -q recap");
	return 0;
}