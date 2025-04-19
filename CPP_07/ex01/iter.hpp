/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:36:41 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/04/19 11:41:20 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename FUNC>
void iter(T *array, size_t length, FUNC func){
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