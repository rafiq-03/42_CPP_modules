/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:55:26 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/11/23 20:46:55 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain( std::string level )
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int lvl = 0;
	for  (lvl = 0; lvl < 4; lvl++)
	{
		if (level == levels[lvl])
		break;
	}
	switch (lvl + 1)
	{
		case 1:
			Harl::debug();
		case 2:
			Harl::info();		
		case 3:
			Harl::warning();		
		case 4:
			Harl::error();
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;		
	}
}

void Harl::debug( void )
{
	std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
void Harl::info( void )
{
	std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}
void Harl::warning( void )
{
	std::cout << "[WARNING]\nthink I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."	<< std::endl;
}
void Harl::error( void )
{
	std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}
