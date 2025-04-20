/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:06:46 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/04/20 16:20:23 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <algorithm>
#include <vector>

#ifndef	DEBUG
#define	DEBUG 0
#endif

class Span
{
	private:
		std::vector<int> _data;
		unsigned int	_size;
		Span(void);
	public:
		Span(unsigned int N);
		Span(const Span& obj);
		Span&	operator=(const Span& obj);
		~Span();
		void	addNumber(int nbr);
		void	addNumbers(std::vector<int>::iterator begin,std::vector<int>::iterator end);
		int		shortestSpan();
		int		longestSpan();

};

#endif
