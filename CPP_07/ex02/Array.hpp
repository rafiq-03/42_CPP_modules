/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:59:18 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/04/18 18:24:57 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

#ifndef DEBUG
#define DEBUG 0
#endif

template<typename T>
class Array
{
	private:
		T		*_Data;
		size_t	_size;
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array& obj);
		Array&	operator=(const Array& obj);
		T&	operator[](unsigned int index);
		size_t	size(void) const;
		~Array();

};

#include "Array.tpp"
#endif

