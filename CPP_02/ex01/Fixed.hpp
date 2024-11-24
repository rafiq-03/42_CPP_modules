/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:49:22 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/24 12:42:23 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		int	_value;
		static const int _fractionalBits;
	public:
		Fixed();
		Fixed(const int value);// ex01;
		Fixed(const float value);// ex01;
		Fixed(const Fixed &other);
		~Fixed();
		Fixed& operator=(const Fixed &other);
		int	getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;// ex01
		int toInt( void ) const;// ex01
};
std::ostream& operator<<(std::ostream &out, const Fixed &a);

#endif
