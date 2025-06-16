/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:06:44 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/06/16 16:26:52 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _size(0)
{
	if (DEBUG)
		std::cout << "Span Default constructor called" << std::endl;
}
Span::Span(unsigned int N) : _size(N)
{
	if (DEBUG)
		std::cout << "Span Default constructor called" << std::endl;
}

Span::~Span(void)
{
	if (DEBUG)
		std::cout << "Span Destructor called" << std::endl;
}

Span::Span(const Span& obj)
{
	if (DEBUG)
		std::cout << "Span Copy constructor called" << std::endl;
	*this = obj;
}

Span& Span::operator=(const Span& obj)
{
	if (DEBUG)
		std::cout << "Span Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		_size = obj._size;
		_data = obj._data;
	}
	return (*this);
}

void	Span::addNumber(int nbr)
{
	if (_data.size() == _size)
		throw std::out_of_range("Adding value is out of range");
	_data.push_back(nbr);
}

void	Span::addNumbers(std::vector<int>::iterator begin,std::vector<int>::iterator end){
	size_t newElements = std::distance(begin, end);
        if (_data.size() + newElements > _size)
            throw std::length_error("No space left in span buffer");
        _data.insert(_data.end(), begin, end);
}


int		Span::shortestSpan(){
	int tmp;
	if (_size < 2)
		throw std::logic_error("invalid size");
	std::sort(_data.begin(), _data.end());
	int	ret = _data[1] - _data[0];
	for (size_t i = 1; i < _data.size(); i++)
	{
		tmp = _data[i] - _data[i - 1];
		if (ret >= tmp)
			ret = tmp;
	}
	return (ret);
}

int		Span::longestSpan(){
	if (_size < 2)
		throw std::logic_error("invalid size");
	return (*std::max_element(_data.begin(), _data.end()) - *std::min_element(_data.begin(), _data.end()));
}

