/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:29:20 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/14 13:26:21 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal(void); // Default constructor
		Animal(const Animal& obj); // Copy constructor
		Animal&	operator=(const Animal& obj); // Copy assigment operator
		virtual ~Animal(); // Destructor
		virtual void makeSound() const = 0;
		std::string getType() const;
};

#endif
