/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:56:53 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/11 18:39:58 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void); // Default constructor
		WrongCat(const WrongCat& obj); // Copy constructor
		WrongCat&	operator=(const WrongCat& obj); // Copy assigment operator
		~WrongCat(); // Destructor
		void makeSound() const;
};

#endif
