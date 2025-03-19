/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:48:47 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/03/18 17:48:57 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include<iostream>

template <typename T>
T max(const T a, const T b)
{
    return(a > b ? a : b);
}

template <typename T>
T min(const T a, const T b)
{
    return(a < b ? a : b);
}

template<class T>
void swap(T &a, T&b)
{
    T tmp;

    tmp  = a;
    a = b;
    b = tmp;
}