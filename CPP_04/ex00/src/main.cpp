/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:29:59 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/11 18:47:29 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongDog.hpp"
#include "../include/WrongCat.hpp"

int main()
{
	std::cout << "+---------[ Animal ]-------------+\n" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

	std::cout << "\n+-------[ WrongAnimal ]---------+\n" << std::endl;
	const WrongAnimal* meta1 = new WrongAnimal();
	const WrongAnimal* j1 = new WrongDog();
	const WrongAnimal* i1 = new WrongCat();
	std::cout << j1->getType() << std::endl;
	std::cout << i1->getType() << std::endl;
	i1->makeSound();
	j1->makeSound();
	meta1->makeSound();
	delete meta1;
	delete j1;
	delete i1;
	return 0;
}
