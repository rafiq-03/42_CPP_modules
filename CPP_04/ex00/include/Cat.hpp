/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:56:53 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/06 11:56:54 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include <iostream>

class Cat
{
	private:

	public:
		Cat(void); // Default constructor
		Cat(const Cat& obj); // Copy constructor
		Cat&	operator=(const Cat& obj); // Copy assigment operator
		~Cat(); // Destructor

};

#endif
