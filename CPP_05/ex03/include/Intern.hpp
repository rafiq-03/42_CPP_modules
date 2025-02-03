/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:33:38 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/01/25 18:18:06 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	private:
		AForm *makeShrubberyCreationForm(std::string Target);
		AForm *makeRobotomyRequestForm(std::string Target);
		AForm *makePresidentialPardonForm(std::string Target);
	public:
		Intern(void);
		Intern(const Intern& obj);
		Intern&	operator=(const Intern& obj);
		~Intern();

		AForm *makeForm(std::string Name, std::string Target);

};

#endif
