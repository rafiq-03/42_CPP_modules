/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:29:02 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/03/17 22:29:03 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void):x(0)
{
	std::cout << "Data Default constructor called" << std::endl;
}

Data::~Data(void)
{
	std::cout << "Data Destructor called" << std::endl;
}

Data::Data(const Data& obj):x(obj.x)
{
	std::cout << "Data Copy constructor called" << std::endl;
}

Data& Data::operator=(const Data& obj)
{
	std::cout << "Data Copy assignment operator called" << std::endl;
	if (this != &obj)
		x = obj.x;
	return (*this);
}

void Data::setX(int x){
	this->x = x;
}

int Data::getX(void){
	return (x);
}
