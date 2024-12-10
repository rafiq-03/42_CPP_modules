/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:49:22 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/09 13:30:44 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		int64_t	_value;
		static const int _fractionalBits;
	public:
		
		// Constructors
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &other);
		
		// Destructor
		
		~Fixed();
		
		//setters && getter
		
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		
		/*----[ Comparison operators: ]----*/
		
		Fixed&	operator=(const Fixed &other);
		bool	operator<(const Fixed &Other) const;
		bool	operator<=(const Fixed &Other) const;
		bool	operator>(const Fixed &Other) const;
		bool	operator>=(const Fixed &Other) const;
		bool	operator==(const Fixed &Other) const;
		bool	operator!=(const Fixed &Other) const;
		
		
		/*----[ Arithmetic operators: ]----*/
		
		Fixed	operator+(const Fixed &other) const;
		Fixed	operator++(int);
		Fixed	&operator++();
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator--(int);
		Fixed	&operator--();
		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;
		
		/*----[ Convertion    :  ]----*/

		float	toFloat( void ) const;
		int		toInt( void ) const;
		
		/*----[ comparaison methodes : ]----*/
		
		static Fixed	&max(Fixed &First, Fixed &Second);
		static Fixed	&min(Fixed &First, Fixed &Second); 
		static const Fixed	&max(const Fixed &First, const Fixed &Second);
		static const Fixed	&min(const Fixed &First, const Fixed &Second); 
		
		/*----[ arithmetic operators: ]----*/
	
};
std::ostream& operator<<(std::ostream &out, const Fixed &a);

#endif
