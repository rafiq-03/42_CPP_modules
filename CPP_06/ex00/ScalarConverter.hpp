/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:07:18 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/03/17 19:15:58 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
#include <iomanip>

#ifndef DEBUG
#define DEBUG 0
#endif

enum Type {CHAR, INT, FLOAT, DOUBLE, SPECIAL, UNDEFINED };
class ScalarConverter
{
	public:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& obj);
		ScalarConverter&	operator=(const ScalarConverter& obj);
		virtual ~ScalarConverter() = 0;

		static	void convert(std::string &input);
};

#endif
