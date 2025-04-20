/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:01:46 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/04/20 15:58:05 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
    try
    {
        int nb = 10;
        Span sp = Span(nb);
        for(int i = 0; i < nb; i++)
        {
            std::srand(i * std::time(NULL));
            int n = std::rand() % 10000;
            std::cout << n << std::endl;
            sp.addNumber(n);
        }
        std::cout << "Longest Span : " << sp.longestSpan() << std::endl;
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}