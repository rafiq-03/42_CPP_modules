/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:20:32 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/03/12 19:21:40 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/Intern.hpp"


int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    std::string name(av[1]);
    try
    {
        Bureaucrat bur("bureaucrat", 1);
        std::cout << bur << std::endl;
        std::cout << "-----------------------------------------------\n" << std::endl;

        Intern maker;

        AForm *form = maker.makeForm(name, "form");
        if (!form)
            throw std::runtime_error("form name not found");
        bur.signForm(*form);
        std::cout << *form << std::endl;
        std::cout << "\n-----------------------------------------------\n" << std::endl;
        bur.executeForm(*form);
        delete form;   
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}