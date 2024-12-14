/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:56:53 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/14 13:22:28 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* _brain;
	public:
		Cat(void); // Default constructor
		Cat(const Cat& obj); // Copy constructor
		Cat&	operator=(const Cat& obj); // Copy assigment operator
		~Cat(); // Destructor
		void makeSound() const;
};

#endif
