/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:56:49 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/11 18:42:33 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat Default constructor called" << std::endl;
	type = "WrongCat";
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj)
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = obj;
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	if (this != &obj)
		type = obj.type;
	return (*this);
}

void WrongCat::makeSound() const{
	std::cout << "WrongCat: Meow Meow" << std::endl;
}