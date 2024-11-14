/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:52:33 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/14 18:44:23 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook Phone;
	std::string input;
	
	std::cout << "\033[32m\t\t**[ WELCOME TO YOUR PHONEBOOK ]**\033[0m" << std::endl;
	sleep(1);
	system("clear");
	std::cout << "\033[34m\t\tLOADING...\033[0m" << std::endl;
	sleep(1);
	system("clear");
	while (1)
	{
		std::cout << "PhoneBook:";
		if (!std::getline(std::cin, input))
			exit(EXIT_FAILURE);
		if (input == "EXIT")
			return (0);
		else if (input == "ADD")
			Phone.setContact();
		else if (input == "SEARCH")
			Phone.getContacts();
	}
	return (0);
}
