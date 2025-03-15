/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:27:08 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/03/15 14:05:03 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", 145, 137), _target("")
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm Parametrized constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj): AForm(obj)
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->setSignedstatus(obj.IsSigned());
	return (*this);
}


void ShrubberyCreationForm::executeAction(void) const {
	std::ofstream file(_target + "_shrubbery");
	if (!file.is_open())
	{
		std::cerr << "Can't open this file" << std::endl;
		return;
	}
	file <<\
	"	    ccoo cc\n"
	"	  ccee88oo 88oo\n"
	"  C8O8O8Q8PoOb o8oo \n"
	" dOB69QO8PdUOpugoO9bD \n"
	"CgggbU8OU qOp qOdoUOdcb \n"
	"    6OuU  /p u gcoUodpP \n"
	"      \\ \\//  /douUP \n"
	"        \\ \\////\n"
	"         |||/\\\n"
	"         |||\\/\n"
	"         |||||\n"
	"   .....//||||\\ .... " << std::endl;
	file.close();
}