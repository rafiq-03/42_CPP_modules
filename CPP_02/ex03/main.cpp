/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:29:18 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/11 12:09:59 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp" 

int main( void )
{
	Point a(0, 1.5f);
	Point b(1, 0);
	Point c(-1, -1);
	Point point(0.27f, 1.1f);
	
	if (bsp(a, b, c, point))
		std::cout << "Inside" << std::endl;
	else
		std::cout << "outside" << std::endl;
	return (0);
}
