/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:33:35 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/01/25 18:20:32 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

Intern::Intern(void)
{
	if (DEBUG)
		std::cout << "Intern Default constructor called" << std::endl;
}

Intern::~Intern(void)
{
	if (DEBUG)
		std::cout << "Intern Destructor called" << std::endl;
}

Intern::Intern(const Intern& obj)
{
	if (DEBUG)
		std::cout << "Intern Copy constructor called" << std::endl;
	(void)obj;
}

Intern& Intern::operator=(const Intern& obj)
{
	if (DEBUG)
		std::cout << "Intern Copy assignment operator called" << std::endl;
	(void)obj;
	return (*this);
}

AForm *Intern::makeForm(std::string Name, std::string Target)
{
	std::string Names[3] = {"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon"};
	AForm*	(Intern::*funcptr[3])(std::string) = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};

	for (int i = 0; i < 3; i++)
	{
		if (Name == Names[i])
			return (this->*funcptr[i])(Target);
	}
	return (NULL);
}

AForm *Intern::makeShrubberyCreationForm(std::string Target)
{
	return (new ShrubberyCreationForm(Target));
}
AForm *Intern::makeRobotomyRequestForm(std::string Target)
{
	return (new RobotomyRequestForm(Target));
}
AForm *Intern::makePresidentialPardonForm(std::string Target)
{
	return (new RobotomyRequestForm(Target));
}
