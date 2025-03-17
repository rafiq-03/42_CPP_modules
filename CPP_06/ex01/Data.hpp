/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:29:06 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/03/17 22:29:07 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP
# include <iostream>

class Data
{
	private:
		int x;
	public:
		Data(void);
		Data(const Data& obj);
		Data&	operator=(const Data& obj);
		~Data();

		void setX(int x);
		int getX(void);
};

#endif
