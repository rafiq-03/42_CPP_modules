/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:04:23 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/04/19 20:15:39 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <list>

int main(void)
{
    try
    {
        std::list<int> list(12);
        std::srand(std::time(NULL));
        for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
            *it = std::rand() % 20;
        std::list<int>::iterator a = easyfind(list, 11);
        std::cout << "found number " << *a << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    

    

    


}