/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:42:24 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/25 15:37:18 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	last = 0;
}
PhoneBook::~PhoneBook()
{
	system("clear");
	std::cout << " **[ CLOSE PHONEBOOK 👋 ]**" << std::endl;
	
}

bool	digits(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

std::string	trim(std::string str)
{
	size_t start, end;

	start = str.find_first_not_of("\t ");
	if (start == std::string::npos)
		return ("");
	end = str.find_last_not_of(" \t");
	return (str.substr(start, end - start + 1));
}

bool whitespaces(std::string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '\t')
			return (true);
	}
	return (false);
}

std::string	check_input(std::string prompt)
{
	std::string input;

	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
			exit(EXIT_FAILURE);
		input = trim(input);
		if (input.empty() || (prompt == "* Phone Number   : " && !digits(input)) || whitespaces(input))
			std::cout << "\033[31mInvalid input !!\033[0m" << std::endl;
		else
			break;
	}
	return (input);
}


void	PhoneBook::setContact()
{
	std::string tmp;

	system("clear");
	std::cout << "+----------------------------------+" << std::endl;
	std::cout << "|      **[  NEW CONTACT  ]**       |" << std::endl;
	std::cout << "+----------------------------------+\n" << std::endl;
	
	tmp = check_input("* First name     : ");
	contacts[last].SetFirstName(tmp);
	tmp = check_input("* Last name      : ");
	contacts[last].SetLastName(tmp);
	tmp = check_input("* Nick Name      : ");
	contacts[last].SetNickName(tmp);
	tmp = check_input("* Phone Number   : ");
	contacts[last].SetPhoneNumber(tmp);
	tmp = check_input("* Darkest Secret : ");
	contacts[last].SetDarkestSecret(tmp);
	if (last == 7)
		last = 0;
	else
		last++;
	system("clear");
	std::cout << "\033[32mContact addes successfully :)\033[0m" << std::endl;
	sleep(1);
	system("clear");
}

std::string	truncate(std::string str)
{
	if (str.size() <= 10)
		return (str);
	std::string trunc = str.substr(0,9);
	trunc.append(".");
	return (trunc);
}


void	PhoneBook::getContacts() const
{
	if (contacts[0].IsEmpty())
		return;
	system("clear");
	std::cout << "+-------------------------------------------+" << std::endl;
	std::cout << "|               Phone Book                  |" << std::endl;
	std::cout << "+-------------------------------------------+" << std::endl;

	std::cout << "|" <<"     index" << "|" <<"First name" << "|" << " Last Name" << "|" << " Nick name" << "|" << std::endl;
	
	std::cout << "+-------------------------------------------+" << std::endl;
	for (int i = 0; !contacts[i].IsEmpty() && i < 8; i++)
	{
		std::cout << "|" << std::setw(10) << i << "|";
		std::cout << std::setw(10) << truncate(contacts[i].GetFirstName()) << "|";
		std::cout << std::setw(10) << truncate(contacts[i].GetLastName()) << "|";
		std::cout << std::setw(10) << truncate(contacts[i].GetNickName()) << "|" << std::endl;
	}
	std::cout << "+-------------------------------------------+" << std::endl;
	std::cout << "\nEnter a Contact ID : ";
	std::string sid;
	if (!std::getline(std::cin, sid))
		exit(EXIT_FAILURE);
	if (sid.length() == 1)
		getOneContact(sid.at(0) - 48);
	else
		std::cout << "\n\033[31mInvalid Contact ID :( \033[0m\n" << std::endl;
}

void	PhoneBook::getOneContact(int i) const
{
	if (i >= 0 && i < 8 && !contacts[i].IsEmpty())
	{
		std::cout << "\n* First Name     : " << contacts[i].GetFirstName() << std::endl;
		std::cout << "* Last Name      : " << contacts[i].GetLastName() << std::endl;
		std::cout << "* Nick Name      : " << contacts[i].GetNickName() << std::endl;
		std::cout << "* Phone Number   : " << contacts[i].GetPhoneNumber() << std::endl;
		std::cout << "* Darkest Secrest: " << contacts[i].GetDarkestSecret() << "\n" <<  std::endl;
	}
	else
		std::cout << "\n\033[31mInvalid Contact ID :( \033[0m\n" << std::endl;
}
