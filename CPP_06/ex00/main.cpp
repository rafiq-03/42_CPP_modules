/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:29:55 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/03/18 11:40:53 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2){
        std::cerr << "Usage: ./convert <value>" << std::endl;
        return (1);
    }
    std::string input = av[1];
    ScalarConverter::convert(input);
    return (0);
}