/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:01:46 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/06/16 16:27:09 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

void test(void){
    std::vector<int> vec;
    std::srand(std::time(NULL));
        for (size_t i = 0; i < 20000; i++)
            vec.push_back(std::rand());
    Span sp(200000);
    sp.addNumbers(vec.begin(), vec.end());
    std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "longest  span: " << sp.longestSpan() << std::endl;
}


int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}
