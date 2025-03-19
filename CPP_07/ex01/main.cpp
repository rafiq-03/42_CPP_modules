/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:41:18 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/03/18 18:11:50 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
    // int array[5] = {13, 33, 99, 65, 7};
    // iter(array, 4, function);
    // for (size_t i = 0; i < 5; i++)
    //     std::cout << array[i] << std::endl;
    std::string *array = new std::string[4];
 
    iter(array, 4, function);
    for (size_t i = 0; i < 5; i++)
        std::cout << array[i] << std::endl;
}