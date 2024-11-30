/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:29:10 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/30 18:59:46 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
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
