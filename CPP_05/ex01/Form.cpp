/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:11:29 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/01/25 11:43:11 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void): _Name(""), _IsSigned(false), _GradeToSigne(1), _GradeToExecute(1)
{
	if (DEBUG)
		std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(std::string Name, int GradeToSigne, int GradeToExecute): _Name(Name), _IsSigned(false), _GradeToSigne(GradeToSigne), _GradeToExecute(GradeToExecute)
{
	if (DEBUG)
		std::cout << "Form Parametrized constructor called" << std::endl;
	if (_GradeToSigne < 1 || _GradeToExecute < 1)
		throw (GradeTooHighException());
	else if (_GradeToSigne > 150 || _GradeToExecute > 150)
		throw (GradeTooLowException());
}

Form::~Form(void)
{
	if (DEBUG)
		std::cout << "Form Destructor called" << std::endl;
}

Form::Form(const Form& obj): _Name(obj._Name), _IsSigned(obj._IsSigned), _GradeToSigne(obj._GradeToSigne), _GradeToExecute(obj._GradeToExecute)
{
	if (DEBUG)
		std::cout << "Form Copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& obj)
{
	if (DEBUG)
		std::cout << "Form Copy assignment operator called" << std::endl;
	if (this != &obj)
		_IsSigned = obj._IsSigned;
	return (*this);
}

std::string	Form::getName(void) const{
	return (_Name);
}

bool		Form::IsSigned(void) const{
	return (_IsSigned);
}

int			Form::getGradeToSigne(void) const{
	return (_GradeToSigne);
}

int			Form::getGradeToExecute(void) const{
	return (_GradeToExecute);
}

void AForm::setSignedstatus(bool status){
	_IsSigned = status;
}

void Form::beSigned(Bureaucrat &bureaucrat){
	if (_GradeToSigne >= bureaucrat.getGrade())
		_IsSigned = true;
	else
		throw (GradeTooLowException());
}

std::ostream	&operator<<(std::ostream &out, const Form &form)
{
	out << "Form: " << form.getName() << ", Is Signed: ";
	form.IsSigned() ? out << "Yes" : out << "No";
	out << ", Grade to Signe: " << form.getGradeToSigne();
	out << ", Grade to Execute: " << form.getGradeToExecute() << ".";
	return (out);
}


const char *Form::GradeTooHighException::what() const throw(){
	return ("Form's Grade is Too High");
}

const char *Form::GradeTooLowException::what() const throw(){
	return ("Form's Grade is Too Low");
}
