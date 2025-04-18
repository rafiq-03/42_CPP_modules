/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:06:44 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/02/11 16:53:10 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : max_size(0), size(0)
{
	if (DEBUG)
		std::cout << "Span Default constructor called" << std::endl;
	_data = new int[0];
}
Span::Span(unsigned int N) : max_size(N), size(0)
{
	if (DEBUG)
		std::cout << "Span Default constructor called" << std::endl;
	_data = new int[N];
}

Span::~Span(void)
{
	if (DEBUG)
		std::cout << "Span Destructor called" << std::endl;
	delete[] _data;
}

Span::Span(const Span& obj)
{
	if (DEBUG)
		std::cout << "Span Copy constructor called" << std::endl;
	max_size = obj.max_size;
	size = obj.size;
	_data = new int[max_size];
	for (size_t i = 0; i < size; i++)
		_data[i] = obj._data[i];
}

Span& Span::operator=(const Span& obj)
{
	if (DEBUG)
		std::cout << "Span Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		delete[] _data;
		size = obj.size;
		max_size = obj.max_size;
		_data = new int[max_size];
		for (size_t i = 0; i < size; i++)
			_data[i] = obj._data[i];
	}
	return (*this);
}

void	Span::addNumber(int nbr)
{
	if (size == max_size)
		throw std::out_of_range("Adding value is out of range");
	_data[size++] = nbr;
}

void	Span::sort(void)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = i + 1; j < size; j++)
			if (_data[i] > _data[j])
			{
				int tmp = _data[i];
				_data[i] = _data[j];
				_data[j] = tmp;
			}
	}
}

int		Span::shortestSpan(){
	int	ret = INT_MAX;
	int tmp;
	if (size == 1 || size == 0)
		throw std::logic_error("invalid number of numbers");
	for (size_t i = 0; i < size - 1; i++)
	{
		tmp = _data[i] - _data[i + 1];
		tmp = tmp > 0 ? tmp : tmp * -1;
		if (ret > tmp)
			ret = tmp;
	}
	return (ret);
}

int		Span::longestSpan(){
	if (size == 1 || size == 0)
		throw std::logic_error("invalid number of numbers");
	this->sort();
	return (_data[size - 1] - _data[0]);
}

