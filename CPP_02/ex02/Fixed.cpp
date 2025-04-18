/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:49:04 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/16 18:27:27 by rmarzouk         ###   ########.fr       */
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
int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);	
}
void Fixed::setRawBits( int const raw ){
	_value = raw;
}
Fixed::Fixed(const int value) : _value (value << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value (roundf(value *(1 << _fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other){
	if (this == &other)
		return (*this);
	std::cout << "Copy assignment operator called" << std::endl;
	_value = other.getRawBits();
	return (*this);
}
Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat( void ) const
{
	return (float)(_value) / (1 << _fractionalBits);
}

int Fixed::toInt( void ) const 
{
	return (_value >> _fractionalBits);
}

std::ostream& operator<<(std::ostream &out, const Fixed &a)
{
	out << a.toFloat();
	return (out);
}

bool Fixed::operator<(const Fixed &Other) const
{
	return (this->getRawBits() < Other.getRawBits() ? true : false);
}

bool Fixed::operator<=(const Fixed &Other) const
{
	return (this->getRawBits() <= Other.getRawBits() ? true : false);
}

bool Fixed::operator>(const Fixed &Other) const
{
	return (this->getRawBits() > Other.getRawBits() ? true : false);
}

bool Fixed::operator>=(const Fixed &Other) const
{
	return (this->getRawBits() >= Other.getRawBits() ? true : false);
}

bool Fixed::operator==(const Fixed &Other) const
{
	return (this->getRawBits() == Other.getRawBits() ? true : false);
}

bool Fixed::operator!=(const Fixed &Other) const
{
	return (this->getRawBits() != Other.getRawBits() ? true : false);
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	res;

	res.setRawBits(this->getRawBits() + other.getRawBits());
	return (res);
} 

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	res;

	res.setRawBits(this->getRawBits() - other.getRawBits());
	return (res);
}

Fixed	Fixed::operator++(int)// a++
{
	Fixed	res = *this;
	
	_value += 1;
	return (res);
}
Fixed	&Fixed::operator++() //++a
{
	_value += 1;
	return (*this);
}

Fixed	&Fixed::operator--() // --a
{
	_value -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int) // --a
{
	Fixed	res = *this;
	_value -= 1;
	return (res);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed	res;

	res.setRawBits((long)(this->getRawBits() * (other.getRawBits()) >> _fractionalBits));
	return (res);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed	res;
	res.setRawBits((this->getRawBits() << _fractionalBits) / other.getRawBits());
	return (res);
}

Fixed	&Fixed::max(Fixed &First, Fixed &Second)
{
	return ((First > Second) ? First : Second);
}

Fixed	&Fixed::min(Fixed &First, Fixed &Second)
{
	return ((First < Second) ? First : Second);
}

const Fixed	&Fixed::max(const Fixed &First, const Fixed &Second)
{
	return ((First > Second) ? First : Second);
}

const Fixed	&Fixed::min(const Fixed &First, const Fixed &Second)
{
	return ((First < Second) ? First : Second);
}
