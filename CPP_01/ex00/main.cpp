/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:57:48 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/06 17:37:04 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"


int main(void)
{
	Zombie *ptr = newZombie("Foo");
	randomChump("Bar");
	ptr->announce();
	// delete(ptr);
}
