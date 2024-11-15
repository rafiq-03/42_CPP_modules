/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:07:45 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/06 18:36:43 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *Horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		Horde[i].setName(name);
		Horde[i].announce();
	}
	return (Horde);
}
