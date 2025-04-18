/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:01:46 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/02/11 17:20:30 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
    int nb = 10000;
    Span sp = Span(nb);
    for(int i = 0; i < nb; i++)
    {
        std::srand(i);
        sp.addNumber(std::rand() % 100000);
    }
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    system("leaks -q span");
return 0; }
