/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:48:53 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/24 13:16:14 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void			Contact::SetFirstName(std::string First)
{
	FirstName = First;
}
void			Contact::SetLastName(std::string Last)
{
	LastName = Last;	
}
void			Contact::SetNickName(std::string Nick)
{
	NickName = Nick;	
}
void			Contact::SetPhoneNumber(std::string Phone)
{
	PhoneNumber = Phone;
}
void			Contact::SetDarkestSecret(std::string Dark)
{
	DarkestSecret = Dark;
}
// getters
std::string		Contact::GetFirstName()
{
	return (FirstName);
}
std::string		Contact::GetLastName()
{
	return (LastName);
}
std::string		Contact::GetNickName()
{
	return (NickName);
}
std::string		Contact::GetPhoneNumber()
{
	return (PhoneNumber);
}
std::string		Contact::GetDarkestSecret()
{
	return (DarkestSecret);
}

bool	Contact::IsEmpty()
{
	if (FirstName.empty() && LastName.empty() && PhoneNumber.empty() && NickName.empty() && DarkestSecret.empty())
		return (true);
	return (false);
}
