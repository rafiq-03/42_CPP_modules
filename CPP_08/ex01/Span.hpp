/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:06:46 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/02/11 16:53:44 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <limits>

#ifndef	DEBUG
#define	DEBUG 0
#endif

class Span
{
	private:
		int	*_data;
		unsigned int	max_size;
		unsigned int	size;
		Span(void);
		void	sort(void);
	public:
		Span(unsigned int N);
		Span(const Span& obj);
		Span&	operator=(const Span& obj);
		~Span();
		void	addNumber(int nbr);
		int		shortestSpan();
		int		longestSpan();

};

#endif
