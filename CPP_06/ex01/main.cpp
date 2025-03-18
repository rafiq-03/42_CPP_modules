/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:29:55 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/03/17 23:44:27 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
    Data *ptr1 = new Data();
    std::cout << "ptr1       : " << ptr1 << std::endl;
    uintptr_t unsignedInt = Serializer::serialize(ptr1);
    std::cout << "unsignedInt:   " << std::hex << unsignedInt << std::endl;
    Data *ptr2 = Serializer::deserialize(unsignedInt);
    std::cout << "ptr2       : " << ptr2 << std::endl;
    delete ptr1;
    return (0);
}