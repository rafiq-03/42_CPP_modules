/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:56:02 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/25 11:11:52 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	int i;
	int	k;
	
	i = 0;
	k = 1;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (k < ac)
	{
		 i = 0;
		while (av[k] && av[k][i])
			std::cout << (char)toupper(av[k][i++]);
		k++;
	}
	std::cout << std::endl;
	return (0);
}
