/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:41:18 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/04/19 12:13:15 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#define LEN 7

int main(void)
{
    double Array[LEN] = {12.5, 33.6, 14.33, 77.32, 90.12, 89.1, 83.14};
    ::iter(Array, LEN , printElement<double>);
}