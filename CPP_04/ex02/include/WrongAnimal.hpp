/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:29:20 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/11 17:05:34 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal(void); // Default constructor
		WrongAnimal(const WrongAnimal& obj); // Copy constructor
		WrongAnimal&	operator=(const WrongAnimal& obj); // Copy assigment operator
		~WrongAnimal(); // Destructor
		void makeSound() const;
		std::string getType() const;
};

#endif
