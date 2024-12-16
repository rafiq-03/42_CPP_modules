/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:39:59 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/14 16:59:36 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void); // Default constructor
		Cure(const Cure& obj); // Copy constructor
		Cure&	operator=(const Cure& obj); // Copy assigment operator
		~Cure(); // Destructor
		Cure* clone() const;// 
		void use(ICharacter& target);
};

#endif
