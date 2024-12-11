/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:56:53 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/11 16:33:46 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat(void); // Default constructor
		Cat(const Cat& obj); // Copy constructor
		Cat&	operator=(const Cat& obj); // Copy assigment operator
		~Cat(); // Destructor
		void makeSound() const;
};

#endif
