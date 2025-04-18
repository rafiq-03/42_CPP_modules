/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:54:18 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/03/27 18:15:05 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <vector>

template<typename T>
typename T::iterator easyfind(T& container, int target)
{
    for(typename T::iterator it(container.begin()); it != container.end(); it++){
        if (*it == target)
            return (it);
    }
    throw std::runtime_error("not found\n");
}

#endif
