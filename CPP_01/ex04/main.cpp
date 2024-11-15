/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:35:23 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/08 16:45:20 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	std::string str1 = av[2];
	std::string str2 = av[3];
	std::string ifile = av[1];
	std::string ofile = ifile + ".replace";
	std::string line;
	
	if (ac != 4 || ifile.empty() || str1.empty() || str2.empty())
	{
		std::cout << "Invalid arguments" << std::endl;
		return (1);
	}
	std::ifstream infile(ifile);
	std::ofstream oufile(ofile);
	if (infile.is_open() && oufile.is_open())
	{
		while (std::getline(infile, line))
		{
			if (line == str1)
				oufile << str2 << std::endl;	
			else
				oufile << line << std::endl;	
		}
	}
	infile.close();
	oufile.close();
	return (0);
}
