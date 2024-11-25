/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:43:14 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/25 15:32:43 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_CPP
#define PHONEBOOK_CPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int	last;

	public:
		PhoneBook();
		~PhoneBook();
	
	void	setContact();
	void	getContacts() const ;
	void	getOneContact(int i) const ;
};

#endif
