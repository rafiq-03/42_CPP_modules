/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:20:32 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/01/25 11:16:45 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"

int main(void)
{
    try
    {
        Form form("tesing", 140, 22);
        Bureaucrat bur("test", 111);
        std::cout << bur << std::endl;
        std::cout << form << std::endl;
        bur.signForm(form);
        std::cout << form << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}