/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:35:35 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/11 11:58:27 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed A, A1, A2, A3, Final;

	A = Point::area(a, b, c);
	A1 = Point::area(point, a, b);
	A2 = Point::area(point, b, c);
	A3 = Point::area(point, c, a);

	if (A1 == 0 || A2 == 0 || A3 == 0)
		return (false);
	Final = A - (A1 + A2 + A3);
	Final < 0 ? Final = Final * -1 : Final;
	return (Final <= 0.005f ? true : false);
}
