/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:29:59 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/24 11:49:13 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongDog.hpp"
#include "../include/WrongCat.hpp"

void	deepCopy(void)
{
	std::cout << "---------[ deep copy test: ]----------\n" << std::endl;
	Cat* catA = new Cat();
	Cat* catB = new Cat(*catA);

	std::cout << "catA : " << catA << std::endl;
	std::cout << "catB : " << catB << std::endl;
	delete catA;
	delete catB;
	std::cout << "\n-----------------------------------\n" << std::endl;
}


int main()
{
	deepCopy();
	std::cout << "---------[ subject test: ]----------\n" << std::endl;
	Animal *cat = new Cat();
	Animal *dog = new Dog();

	delete cat;
	delete dog;
	std::cout << "\n-----------------------------------\n" << std::endl;
	Animal* animals[6];

	for (int i = 0; i < 6; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		animals[i]->makeSound();
	}
	for(int i = 0; i < 6; i++)
		delete animals[i];
	std::cout << "\n-----------------------------------\n" << std::endl;
	system("leaks -q Animal");
	return 0;
}

