/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:29:18 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/10 16:25:13 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp" 

int main( void )
{
	Point array[10][4] = {
		{Point(0, 0), Point(10, 30), Point(20, 0), Point(15, 10)},// inside
		{Point((-1), 6), Point(6, 3), Point(0, 0), Point(2, 1)},
		{Point(0.51, 1.49), Point(-3, 4), Point(4, 1), Point(0, 0)},
		{Point(0, 0), Point(10, 30), Point(20, 0), Point(15, 10)},
		{Point((-1), 6), Point(6, 3), Point(0, 0), Point(2, 1)},
		{Point(0.51, 1.49), Point(-3, 4), Point(4, 1), Point(0, 0)},
		{Point(0, 0), Point(10, 30), Point(20, 0), Point(15, 10)},
		{Point((-1), 6), Point(6, 3), Point(0, 0), Point(2, 1)},
		{Point(0.51, 1.49), Point(-3, 4), Point(4, 1), Point(0, 0)},
		{Point(0, 0), Point(10, 30), Point(20, 0), Point(15, 10)}
	};
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Triangle " << i + 1 << " : ";
		if (bsp(array[i][0], array[i][1], array[i][2], array[i][3]))
			std::cout << "Inside" << std::endl;
		else
			std::cout << "outside" << std::endl;
	}
	return (0);
}
