/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:07:30 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/14 12:11:37 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain Default constructor called" << std::endl;
	// we don't need to initialize ideas array because it's a string array
}

Brain::~Brain(void)
{
	std::cout << "Brain Destructor called" << std::endl;
	// we don't need to delete ideas array because it's a string array
}

Brain::Brain(const Brain& obj)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	*this = obj;
}

Brain& Brain::operator=(const Brain& obj)
{
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		for(int i = 0; i < 100; i++)
			_ideas[i] = obj._ideas[i];
	}
	return (*this);
}

std::string Brain::getIdea(int i) const
{
	if (i < 0 || i >= 100)
		return "";
	return (_ideas[i]);
}

void Brain::setIdea(int i, std::string idea)
{
	if (i < 0 || i >= 100)
		return ;
	_ideas[i] = idea;
}