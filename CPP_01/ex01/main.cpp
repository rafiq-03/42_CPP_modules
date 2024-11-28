/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:40:31 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/23 18:55:54 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int n = 8;
	Zombie *Horde = zombieHorde(n, "name");
	std::string strings[8] = {"Kaii" ,"Noah" ,"Miaa" ,"Avaa" ,"Mila" ,"Aria" ,"Luna" ,"Luca"};
	for (int i = 0; i < n; i++)
		Horde[i].setName(strings[i]);
	for (int i = 0; i < n; i++)
		Horde[i].announce();
	delete[] Horde;
	return (0);
}
