/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:53:34 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/02/06 18:01:15 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
    try{
        Array<int> array(4);
        array[6] = 4;
        std::cout << array[1] << std::endl;
    }
    catch(std::out_of_range &e)
    {
        std::cout << e.what() << std::endl;
    }



}