/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:23:13 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/02/11 19:00:36 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
int main()
{
    MutantStack<int> mstack;
    mstack.push(5); mstack.push(17);
    std::cout << mstack.top() << std::endl; mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3); mstack.push(5); mstack.push(737); //[...] mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin(); MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
    ++it; }
    std::stack<int> s(mstack);
    return 0;
}
