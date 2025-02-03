/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:11:29 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/01/25 11:21:44 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

AForm::AForm(void): _Name(""), _IsSigned(false), _GradeToSigne(1), _GradeToExecute(1)
{
	if (DEBUG)
		std::cout << "AForm Default constructor called" << std::endl;
}

AForm::AForm(std::string Name, int GradeToSigne, int GradeToExecute): _Name(Name), _IsSigned(false), _GradeToSigne(GradeToSigne), _GradeToExecute(GradeToExecute)
{
	if (DEBUG)
		std::cout << "AForm Parametrized constructor called" << std::endl;
	if (_GradeToSigne < 1 || _GradeToExecute < 1)
		throw (GradeTooHighException());
	else if (_GradeToSigne > 150 || _GradeToExecute > 150)
		throw (GradeTooLowException());
}

AForm::~AForm(void)
{
	if (DEBUG)
		std::cout << "AForm Destructor called" << std::endl;
}

AForm::AForm(const AForm& obj): _Name(obj._Name), _IsSigned(obj._IsSigned), _GradeToSigne(obj._GradeToSigne), _GradeToExecute(obj._GradeToExecute)
{
	if (DEBUG)
		std::cout << "AForm Copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& obj)
{
	if (DEBUG)
		std::cout << "AForm Copy assignment operator called" << std::endl;
	if (this != &obj)
		_IsSigned = obj._IsSigned;
	return (*this);
}

std::string	AForm::getName(void) const{
	return (_Name);
}

bool		AForm::IsSigned(void) const{
	return (_IsSigned);
}

int			AForm::getGradeToSigne(void) const{
	return (_GradeToSigne);
}

int			AForm::getGradeToExecute(void) const{
	return (_GradeToExecute);
}

void AForm::setSignedstatus(bool status){
	_IsSigned = status;
}

void AForm::beSigned(Bureaucrat &bureaucrat){
	if (_GradeToSigne >= bureaucrat.getGrade())
		_IsSigned = true;
	else
		throw (GradeTooLowException());
}

void AForm::execute(Bureaucrat const & executor) const{
	if (!_IsSigned)
		throw (NotSignedException());
	else if (executor.getGrade() >= _GradeToExecute)
		throw (Bureaucrat::GradeTooLowException());// need to check it later
	executeAction();
}

std::ostream	&operator<<(std::ostream &out, const AForm &form)
{
	out << "AForm: " << form.getName() << ", Is Signed: ";
	form.IsSigned() ? out << "Yes" : out << "No";
	out << ", Grade to Signe: " << form.getGradeToSigne();
	out << ", Grade to Execute: " << form.getGradeToExecute() << ".";
	return (out);
}


const char *AForm::NotSignedException::what() const throw(){
	return ("Form is Not signed !");
}

const char *AForm::GradeTooHighException::what() const throw(){
	return ("AForm's Grade is Too High");
}

const char *AForm::GradeTooLowException::what() const throw(){
	return ("AForm's Grade is Too Low");
}
