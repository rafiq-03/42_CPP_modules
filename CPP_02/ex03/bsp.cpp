/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:35:35 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/15 12:15:03 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed A, A1;

	A = Point::area(a, b, c);
	A1 = Point::area(point, a, b);
	A1 = A1 + Point::area(point, b, c);
	A1 = A1 + Point::area(point, c, a);
	
	return (A == A1 ? true : false);
}
