/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:28:10 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/01/25 11:14:06 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _Name(""), _Grade(150)
{
	if (DEBUG)
		std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string Name, int Grade): _Name(Name)
{
	if (DEBUG)
		std::cout << "Bureaucrat Parametrized constructor called" << std::endl;
	if (Grade > 150)
		throw GradeTooLowException();
	else if (Grade < 1)
		throw GradeTooHighException();
	_Grade = Grade;
}

Bureaucrat::~Bureaucrat(void)
{
	if (DEBUG)
		std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj)
{
	if (DEBUG)
		std::cout << "Bureaucrat Copy constructor called" << std::endl;
	_Grade = obj._Grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	if (DEBUG)
		std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
	if (this != &obj)
		_Grade = obj._Grade;
	return (*this);
}


std::string	Bureaucrat::getName(void) const {
	return (_Name);
}

int			Bureaucrat::getGrade(void) const {
	return (_Grade);
}

void Bureaucrat::incrementGrade(void){
	if (_Grade == 1)
		throw GradeTooHighException();
	_Grade--;
}

void Bureaucrat::decrementGrade(void){
	if (_Grade == 150)
		throw GradeTooLowException();
	_Grade++;
}

void Bureaucrat::signForm(Form &form){
	try
	{
		form.beSigned(*this);
		std::cout << _Name <<" signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _Name << " couldn't sign " << form.getName() <<" because " << e.what() << std::endl;
	}
	
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
	return ("Bureaucrat's Grade is Too High");
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return ("Bureaucrat's Grade is Too Low");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (out);
}

