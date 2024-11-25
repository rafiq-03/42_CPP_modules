/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:13:05 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/25 11:23:01 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <unistd.h>
#include <iomanip>

class Contact
{
	private:
		std::string FirstName;
		std::string LastName;
		std::string NickName;
		std::string PhoneNumber;
		std::string DarkestSecret;

	public:
		// setters
		void			SetFirstName(std::string First);
		void			SetLastName(std::string Last);
		void			SetNickName(std::string Nick);
		void			SetPhoneNumber(std::string Phone);
		void			SetDarkestSecret(std::string Dark);
		// getters
		std::string		GetFirstName() const;
		std::string		GetLastName() const;
		std::string		GetNickName() const;
		std::string		GetPhoneNumber() const;
		std::string		GetDarkestSecret() const;

		bool	IsEmpty() const;
};

#endif
