/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:29:10 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/11 12:50:16 by rmarzouk         ###   ########.fr       */
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
		
		FragTrap();// default
		FragTrap(const std::string& Name);// parametrized
		FragTrap(FragTrap &other); // copy constructor

		FragTrap &operator=(const FragTrap &other);// copy assignement operator
	
		/*--------[destructor :]-----------------*/
		
		~FragTrap();// destructor

		/*--------[methodes :]-----------------*/
		
		void attack(const std::string& target);
		void highFivesGuys(void);
};



#endif
