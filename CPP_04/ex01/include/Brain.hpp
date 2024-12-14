/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:07:43 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/14 10:44:53 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
	private:
		std::string _ideas[100];
	public:
		Brain(void); // Default constructor
		Brain(const Brain& obj); // Copy constructor
		Brain&	operator=(const Brain& obj); // Copy assigment operator
		std::string getIdea(int i) const;
		void setIdea(int i, std::string idea);
		~Brain(); // Destructor

};

#endif
