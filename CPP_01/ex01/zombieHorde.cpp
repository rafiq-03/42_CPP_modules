/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:07:45 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/28 12:14:44 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
	{
		std::cout << "can't allocate this number" << std::endl;
		return (NULL);
	}
	Zombie *Horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		Horde[i].setName(name);
	}
	return (Horde);
}
