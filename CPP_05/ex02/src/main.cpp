/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:20:32 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/03/12 18:01:28 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"

int main(void)
{
    try
    {
        Bureaucrat bur("bureacrat", 1);
        std::cout << bur << std::endl << std::endl;

        ShrubberyCreationForm form1("target1");
        RobotomyRequestForm form2("target2");
        PresidentialPardonForm form3("target3");
        
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;
        std::cout << form3 << "\n" << std::endl;
        
        bur.signForm(form1);
        bur.signForm(form2);
        bur.signForm(form3);

        std::cout << std::endl;
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;
        std::cout << form3 << std::endl;
        std::cout << std::endl;
        
        bur.executeForm(form1);
        std::cout << std::endl;
        bur.executeForm(form2);
        std::cout << std::endl;
        bur.executeForm(form3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}