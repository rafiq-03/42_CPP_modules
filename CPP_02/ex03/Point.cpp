/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:36:20 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/11 12:14:38 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0){}

Point::Point(const Point &other): _x(other.get_x()), _y(other.get_y()){}

Point::Point(const float x, const float y) : _x(x), _y(y){}

Point	&Point::operator=(const Point &other)
{
	(void)other;
	return (*this);
}

Fixed	Point::get_x(void) const {return (_x);}
Fixed	Point::get_y(void) const {return (_y);}

Point::~Point() {/*std::cout << "destructor called" << std::endl;*/}

Fixed Point::area(Point const &a, Point const &b, Point const &c)
{
	Fixed Area;

	Area = (a.get_x() * (b.get_y() - c.get_y()) + b.get_x() * (c.get_y() - a.get_y()) + c.get_x() * (a.get_y() - b.get_y())) / 2;
	return (Area >= 0 ? Area : Area * (-1));
}
