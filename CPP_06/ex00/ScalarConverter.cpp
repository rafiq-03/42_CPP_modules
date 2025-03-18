/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:07:14 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/03/18 11:27:06 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	if (DEBUG)
		std::cout << "ScalarConverter Default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter(void)
{
	if (DEBUG)
		std::cout << "ScalarConverter Destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
	if (DEBUG)
		std::cout << "ScalarConverter Copy constructor called" << std::endl;
	static_cast<void>(obj);
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
	if (DEBUG)
		std::cout << "ScalarConverter Copy assignment operator called" << std::endl;
	static_cast<void>(obj);
	return (*this);
}

static bool	isInt(const std::string &input){
	size_t i = 0;
	if (input[0] == '-' || input[0] == '+')
		i++;
	while (i < input.size())
	{
		if (!isdigit(input[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool	isDouble(const std::string &input){
	size_t	i 			= 0;
	int		DotCounter	= 0;
	if (input[i] == '-' || input[i] == '+')
		i = 1;
	while (i < input.size())
	{
		if (input[i] == '.'){
			if (i == input.size() - 1)
				return (false);
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

static bool	isFloat(const std::string &input){
	size_t	i 			= 0;
	int		DotCounter	= 0;

	if (input[0] == '-' || input[0] == '+')
		i++;
	while (i < input.size() - 1)
	{
		if (input[i] == '.'){
			if (input[i + 1] == 'f')
				return (false);
			DotCounter++;
			i++;
			continue;
		}
		if (!isdigit(input[i]))
			return (false);
		i++;
	}
	return (DotCounter == 1 && input[i] == 'f');
}

Type	getType(const std::string &input){
	if (input == "nan" || input == "nanf" || input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff")
		return (SPECIAL);
	else if (input.length() == 1 && !isdigit(input[0]) && isprint(input[0]))
		return (CHAR);
	else if (isInt(input))
		return (INT);
	else if (isDouble(input))
		return (DOUBLE);
	else if (isFloat(input))
		return (FLOAT);
	else
		return (UNDEFINED);
}

static void convertToChar(std::string &input, double value, Type type){
	std::cout << "char: ";
	if (type == CHAR){
		std::cout << input << std::endl;
	}
	else if (type == SPECIAL){
		std::cout << "impossible" << std::endl;
	}
	else if (std::isprint(static_cast<int>(value)))
		std::cout << static_cast<char>(value) << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

static void convertToInt(std::string &input, double value, Type type){
	std::cout << "int: ";
	if (type == SPECIAL)
		std::cout << "impossible" << std::endl;
	else if (type == CHAR)
		std::cout << static_cast<int>(input[0]) << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

static void convertToFloat(std::string &input, double value, Type type){
	std::cout << "float: ";
	if (type == CHAR)
		std::cout << static_cast<float>(input[0]) << ".0f" << std::endl;
	else if (type == SPECIAL)
	{
		if (input == "nan" || input == "+inf" || input == "-inf")
			std::cout << input << "f" << std::endl;
		else
			std::cout << input << std::endl;
	}
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
}

static void convertToDouble(std::string &input, double value, Type type){
	std::cout << "double: ";
	if (type == CHAR)
		std::cout << static_cast<double>(input[0]) << ".0" << std::endl;
	else if (type == SPECIAL)
	{
		if (input == "nan" || input == "+inf" || input == "-inf")
			std::cout << input << std::endl;
		else
			std::cout << input.erase(input.length() - 1) << std::endl;
	}
	else
		std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}

void ScalarConverter::convert(std::string &input) {
	Type _type = getType(input);
	if (_type == UNDEFINED){
		std::cerr << "Invalid Input" << std::endl;
		return;
	}
	double value = std::strtod(input.c_str(), NULL);
	convertToChar(input, value, _type);
	convertToInt(input, value, _type);
	convertToFloat(input, value, _type);
	convertToDouble(input, value, _type);
}