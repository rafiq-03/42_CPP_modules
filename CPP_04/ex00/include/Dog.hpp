/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:29:34 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/11 16:34:02 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog(void); // Default constructor
		Dog(const Dog& obj); // Copy constructor
		Dog&	operator=(const Dog& obj); // Copy assigment operator
		~Dog(); // Destructor
		void makeSound()const;
};

#endif
