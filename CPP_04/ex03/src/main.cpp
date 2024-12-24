/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:35:36 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/24 13:42:37 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"
#include "../include/ICharacter.hpp"
#include "../include/Character.hpp"
#include "../include/Cure.hpp"
#include "../include/Ice.hpp"
#include "../include/MateriaSource.hpp"
#include "../include/IMateriaSource.hpp"

void	subjectTest(){
	std::cout << "------------[ Subject test ]-----------\n" << std::endl;
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
	std::cout << "\n---------------------------------------\n" << std::endl;
}

void	myTest(){
	std::cout << "--------------[ My test ]--------------\n" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("El-Madani");
	ICharacter *enemy = new Character("chiwahed");
	for (size_t i = 0; i < 4; i++)
	{
		if (i % 2 != 0){
			AMateria* tmp = src->createMateria("ice");
			me->equip(tmp);
		}
		else {
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
	me->unequip(2);
	me->use(1, *enemy);
	delete src;
	delete me;
	delete enemy;
	delete tmp;
	std::cout << "\n---------------------------------------\n" << std::endl;
}

int main(void)
{
	subjectTest();
	myTest();
	system("leaks -q recap");
	return 0;
}