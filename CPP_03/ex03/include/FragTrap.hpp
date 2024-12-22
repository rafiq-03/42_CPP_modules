/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:29:10 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/22 17:58:56 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:

		/*--------[constructors :]-----------------*/
		
		FragTrap();
		FragTrap(unsigned int Hit, unsigned int attack);
		FragTrap(const std::string& Name);
		FragTrap(FragTrap &other);

		FragTrap &operator=(const FragTrap &other);
	
		/*--------[destructor :]-----------------*/
		
		~FragTrap();

		/*--------[methodes :]-----------------*/
		
		void attack(const std::string& target);
		void highFivesGuys(void);
};



#endif
