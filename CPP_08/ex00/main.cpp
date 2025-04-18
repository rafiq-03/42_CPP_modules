/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:04:23 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/02/07 18:28:06 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"

int main(void)
{
    try
    {
        std::vector<int> vector(12, 1);
        std::vector<int>::iterator a = easyfind(vector, 11);
        std::cout << "a = " << *a << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    

    


}