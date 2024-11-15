/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:57:45 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/06 17:38:13 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	Zombie
{
	private:
		std::string	name;
		
	public:
	void announce( void );
	Zombie(std::string name);
	~Zombie();
		
};

void	randomChump( std::string name );
Zombie*	newZombie( std::string name );
