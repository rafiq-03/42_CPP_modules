/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:07:14 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/02/06 15:36:13 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "ScalarConverter Default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScalarConverter Destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
	(void)obj;
	std::cout << "ScalarConverter Copy constructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
	std::cout << "ScalarConverter Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		// Add any assignment logic here
	}
	return (*this);
}

bool	isInt(std::string &input){
	size_t i = 0;
	if (input.at(0) == '-' || input.at(0) == '+')
		i = 1;
	while (i < input.size())
	{
		if (!isdigit(input.at(i)))
			return (false);
		i++;
	}
	return (true);
}

bool	isFloat(std::string &input){
	size_t	i 			= 0;
	int		DotCounter	= 0;

	if (input.at(0) == '-' || input.at(0) == '+')
		i = 1;
	while (i < input.size() - 1)
	{
		if (input.at(i) == '.'){
			DotCounter++;
			i++;
			continue;
		}
		if (!isdigit(input.at(i)))
			return (false);
		i++;
	}
	return (DotCounter == 1 && input.at(i) == 'f');
}

bool	isDouble(std::string &input){
	size_t	i 			= 0;
	int		DotCounter	= 0;
	if (input.at(0) == '-' || input.at(0) == '+')
		i = 1;
	while (i < input.size())
	{
		if (input.at(i) == '.'){
			DotCounter++;
			i++;
			continue;
		}
		if (!isdigit(input.at(i)))
			return (false);
		i++;
	}
	return (DotCounter == 1);
}

bool isSpecial(const std::string& input) {
    return (input == "nan" || input == "nanf" || input == "+inf" 
			|| input == "-inf" || input == "+inff" || input == "-inff");
}

void ScalarConverter::convert(std::string &input) {
    int i;
    float f;
    double d;
    char c;
    
    if (isInt(input)) {
        i = std::atoi(input.c_str());
        f = static_cast<float>(i);
        d = static_cast<double>(i);
        c = static_cast<char>(i);
    }
    else if (isFloat(input)) {
        f = std::atof(input.c_str());
        d = static_cast<double>(f);
        i = static_cast<int>(f);
        c = static_cast<char>(i);
    }
    else if (isDouble(input)) {
        d = std::atof(input.c_str());
        f = static_cast<float>(d);
        i = static_cast<int>(d);
        c = static_cast<char>(i);
    }
    else if (isSpecial(input)) {
		if (input[4])
			input[4] = '\0';
		std::cout << "char  : " << "impossible" << std::endl;
		std::cout << "int   : " << "impossible" << std::endl;
		std::cout << "float : " << input << "f" << std::endl;
		std::cout << "double: " << input << std::endl;
		return;
    }
    else {
        std::cout << "Invalid input" << std::endl;
        return;
    }
	if ((i >= 32 && i <= 126))
    	std::cout << "char  : " <<  c << std::endl;
	else
		std::cout << "char  : Non displayable" << std::endl;
    std::cout << "int   : " << i << std::endl;
    std::cout << "float : " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

