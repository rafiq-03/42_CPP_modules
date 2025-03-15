/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:33:18 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/03/12 18:04:12 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 72, 45), _target("")
{
	if (DEBUG)
		std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	if (DEBUG)
		std::cout << "RobotomyRequestForm Parametrized constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	if (DEBUG)
		std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj): AForm(obj)
{
	if (DEBUG)
		std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	if (DEBUG)
		std::cout << "RobotomyRequestForm Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->setSignedstatus(obj.IsSigned());
	return (*this);
}


void RobotomyRequestForm::executeAction(void) const {
	std::cout << "Makes some drilling noises..." << std::endl;
	std::srand(std::time(NULL));
    if (std::rand() % 2){
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy of " << _target << " failed." << std::endl;
    }
}