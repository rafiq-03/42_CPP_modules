/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:35:46 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/15 11:15:30 by rmarzouk         ###   ########.fr       */
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
	Point(Point &other);
	Point(const float x, const float y);
	Point	&operator=(Point &other);
	~Point();

	void	set_x(const Fixed val);
	void	set_y(const Fixed val);

	Fixed	get_x(void)const ;
	Fixed	get_y(void)const ;

	static Fixed area(Point const &a, Point const &b, Point const &c);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
