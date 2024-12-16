/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:39:54 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/15 15:45:52 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include <iostream>
#include "ICharacter.hpp"

class Ice : public AMateria
{
	public:
		Ice(void); // Default constructor
		Ice(const Ice& obj); // Copy constructor
		Ice&	operator=(const Ice& obj); // Copy assigment operator
		~Ice(); // Destructor
		Ice* clone() const;
		void use(ICharacter& target);
};

#endif
