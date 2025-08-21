/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:08:39 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/08/21 16:39:26 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    try
    {
        int length = 1;
        if (ac < 2)
            throw std::runtime_error("Error");
        (void)av;
        PmergeMe p(ac, av);
        std ::cout << "Count " << p.count;
        // std::deque<int> arr;
        // for (size_t i = 0; i < p.dequeChain.size(); i+=length)
        // {
        //    arr.insert(arr.begin()+ p.chkek(arr,p.dequeChain[i],length), p.dequeChain[i]) ;
        // }

        // std::cout << " ********* " << std::endl;
        // for (size_t i = 0; i < arr.size(); i++)
        // {
        //    std::cout << arr[i] << " " ;
        // }
        // std::cout << "pow : " << pow(2, 3) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
