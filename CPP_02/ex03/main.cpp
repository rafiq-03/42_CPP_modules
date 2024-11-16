/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:29:18 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/15 12:22:08 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp" 

int main( void )
{
	// Point **arr = new Point *[10];
	// Point *tst = new Point [4];
	Point a(0, 0), b(10, 30), c(20, 0), point(15, 15);
	if (bsp(a, b, c, point))
		std::cout << "Inside" << std::endl;
	else
		std::cout << "outside" << std::endl;
	return (0);
}
