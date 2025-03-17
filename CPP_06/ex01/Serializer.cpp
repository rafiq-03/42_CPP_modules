/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:51:53 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/03/17 22:31:03 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << "Serializer Default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer& obj)
{
	std::cout << "Serializer Copy constructor called" << std::endl;
	static_cast<void>(obj);
}

Serializer& Serializer::operator=(const Serializer& obj)
{
	std::cout << "Serializer Copy assignment operator called" << std::endl;
	static_cast<void>(obj);
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t	raw;

	raw = reinterpret_cast<uintptr_t>(ptr);
	return (raw);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data *ptr;

	ptr = reinterpret_cast<Data *>(raw);
	return (ptr);
}
