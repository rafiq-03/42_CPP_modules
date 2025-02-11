/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:40:25 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/02/06 18:06:35 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T> T max(const T a, const T b)
{
    return(a > b ? a : b);
}

template <typename T> T min(const T a, const T b)
{
    return(a < b ? a : b);
}

template<class T> void swap(T &a, T&b)
{
    T tmp;

    tmp  = a;
    a = b;
    b = tmp;
}


int main( void ) 
{ 
    // int a = 2;
    // int b = 3;
    // ::swap( a, b );
    // std::cout << "a = " << a << ", b = " << b << std::endl;
    // std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
    // std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;
    // std::string c = "chaine1";
    // std::string d = "chaine2";
    // ::swap(c, d);
    // std::cout << "c = " << c << ", d = " << d << std::endl;
    // std::cout << "min(c, d) = " << ::min( c, d ) << std::endl;
    // std::cout << "max(c, d) = " << ::max( c, d ) << std::endl;

    max<int>(12, 15)
return 0; }