/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:34:19 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/24 12:55:08 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>
#include "ICharacter.hpp"

#ifndef D_MODE
# define D_MODE 1
#endif
class ICharacter;

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
		virtual void use(ICharacter& target);
};

#endif
