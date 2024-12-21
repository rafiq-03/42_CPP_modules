/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:29:10 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/21 14:44:58 by rmarzouk         ###   ########.fr       */
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
