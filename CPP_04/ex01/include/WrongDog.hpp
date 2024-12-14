/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:29:34 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/11 18:41:10 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP
# include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
	public:
		WrongDog(void); // Default constructor
		WrongDog(const WrongDog& obj); // Copy constructor
		WrongDog&	operator=(const WrongDog& obj); // Copy assigment operator
		~WrongDog(); // Destructor
		void makeSound()const;
};

#endif
