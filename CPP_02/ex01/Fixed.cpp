/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:49:04 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/24 12:41:40 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(): _value(0){
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}
Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}
Fixed& Fixed::operator=(const Fixed &other){
	std::cout << "Copy assignment operator called" << std::endl;
	_value = other.getRawBits();
	return (*this);
}
int	Fixed::getRawBits( void ) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (_value);	
}
void Fixed::setRawBits( int const raw ){
	_value = raw;
}

Fixed::Fixed(const int value) : _value (value << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value (roundf(value *(1 << _fractionalBits)))// to do
{
	std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat( void ) const// to do 
{
	return (float)(_value) / (1 << _fractionalBits);
}

int Fixed::toInt( void ) const// to do 
{
	return (_value >> _fractionalBits);
}

std::ostream& operator<<(std::ostream &out, const Fixed &a)
{
	out << a.toFloat();
	return (out);
}
