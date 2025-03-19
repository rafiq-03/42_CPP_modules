/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:36:41 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/03/19 17:18:41 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, size_t length, void func(T&)){
    if (!array)
        return ;
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}

template<typename T> 
void printElement(T &element)
{
    std::cout << element << std::endl;
}

#endif