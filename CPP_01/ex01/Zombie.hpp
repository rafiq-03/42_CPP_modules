/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:41:26 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/06 18:36:27 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
	private:
		std::string	name;
	public:
	void	announce( void );
	void	setName(std::string name);
	Zombie();
	~Zombie();
};

Zombie* zombieHorde( int N, std::string name );
