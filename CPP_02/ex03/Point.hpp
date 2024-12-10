/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:35:46 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/10 12:14:50 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed	_x;	
		Fixed	_y;
	public:
	Point();	
	Point(const Point &other);
	Point(const float x, const float y);
	Point	&operator=(const Point &other);
	~Point();

	void	set_x(const Fixed val);
	void	set_y(const Fixed val);

	Fixed	get_x(void)const ;
	Fixed	get_y(void)const ;

	static Fixed area(Point const &a, Point const &b, Point const &c);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
