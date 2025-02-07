/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:07:18 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/02/06 15:27:12 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
#include <iomanip>

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
