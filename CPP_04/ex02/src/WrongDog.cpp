/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:34:29 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/24 11:21:01 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongDog.hpp"

WrongDog::WrongDog(void)
{
	type = "WrongDog";
	std::cout << "WrongDog Default constructor called" << std::endl;
}

WrongDog::~WrongDog(void)
{
	std::cout << "WrongDog Destructor called" << std::endl;
}

WrongDog::WrongDog(const WrongDog& obj)
{
	std::cout << "WrongDog Copy constructor called" << std::endl;
	*this = obj;
}

WrongDog& WrongDog::operator=(const WrongDog& obj)
{
	std::cout << "WrongDog Copy assignment operator called" << std::endl;
	if (this != &obj)
		type = obj.type;
	return (*this);
}

void	WrongDog::makeSound(void) const
{
	std::cout << "WrongDog: Bark Bark" << std::endl;
}
