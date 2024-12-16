/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:34:19 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/15 13:34:52 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>
#include "ICharacter.hpp"// need to check later loop back include

class ICharacter;// prevent dependency include

class AMateria
{
	protected:
		std::string _Type;

	public:
		AMateria(void); // Default constructor
		AMateria(std::string const & type);//parameterized constructor
		AMateria(const AMateria& obj); // Copy constructor
		AMateria&	operator=(const AMateria& obj); // Copy assigment operator
		std::string const & getType() const; // Returns the materia type
		virtual	~AMateria(); // Destructor

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);// to do 
};

#endif
