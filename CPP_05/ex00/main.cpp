/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:20:32 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/01/24 20:49:54 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

void GradeTooHigh(void)
{
    Bureaucrat High("High", 3);
    for (int i = 0; i < 3 ; i++)
    {
        std::cout << High << std::endl;
        High.incrementGrade();
    }
}

void GradeTooLow(void)
{
    Bureaucrat Low("Low", 148);
    for (int i = 0; i < 3 ; i++)
    {
        std::cout << Low << std::endl;
        Low.decrementGrade();
    }
}

int main(void)
{
    std::string input;
    try
    {
        std::cout << "\nchoose h for High or l for Low : ";
        std::cin >> input;
        if (input == "l")
            GradeTooLow();
        else if (input == "h")
            GradeTooHigh();
        else
            std::cerr << "invalid option !!" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}