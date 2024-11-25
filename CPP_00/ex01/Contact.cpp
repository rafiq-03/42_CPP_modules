/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:48:53 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/25 11:23:17 by rmarzouk         ###   ########.fr       */
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
std::string		Contact::GetFirstName() const
{
	return (FirstName);
}
std::string		Contact::GetLastName() const
{
	return (LastName);
}
std::string		Contact::GetNickName() const
{
	return (NickName);
}
std::string		Contact::GetPhoneNumber() const
{
	return (PhoneNumber);
}
std::string		Contact::GetDarkestSecret() const
{
	return (DarkestSecret);
}

bool	Contact::IsEmpty() const
{
	if (FirstName.empty() && LastName.empty() && PhoneNumber.empty() && NickName.empty() && DarkestSecret.empty())
		return (true);
	return (false);
}
