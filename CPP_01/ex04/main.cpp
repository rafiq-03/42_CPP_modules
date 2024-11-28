/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:35:23 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/28 12:32:03 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char **av)// need to check it later
{
	if (ac != 4)
	{
		std::cout << "Invalid arguments" << std::endl;
		return (1);
	}
	std::string str1 = av[2];
	std::string str2 = av[3];
	std::string ifile = av[1];
	std::string ofile = ifile + ".replace";
	std::string line;

	if (ifile.empty() || str1.empty())
	{
		std::cout << "Invalid arguments" << std::endl;
		return (1);
	}
	std::ifstream infile(ifile);
	if (!infile.is_open())
		return(1);
	std::ofstream oufile(ofile);
	if (!oufile.is_open())
		return (1);
	while (std::getline(infile, line))
	{
		std::size_t found = line.find(str1, 0);
		while (found != std::string::npos)
		{
			line.erase(found, str1.size());
			line.insert(found, str2);
			found = line.find(str1, found + str2.size());
		}
		if (!infile.eof())
			oufile << line << std::endl;
	}
	oufile.close();
	infile.close();
	return (0);
}
