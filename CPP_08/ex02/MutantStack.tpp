/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:30:05 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/06/16 17:03:53 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
MutantStack<T>::MutantStack(void)
{
	if (DEBUG)
		std::cout << "MutantStack Default constructor called" << std::endl;
}
template <typename T>
MutantStack<T>::~MutantStack(void)
{
	if (DEBUG)
		std::cout << "MutantStack Destructor called" << std::endl;
}
template <typename T>
MutantStack<T>::MutantStack(const MutantStack& obj) : std::stack<T>(obj)
{
	if (DEBUG)
		std::cout << "MutantStack Copy constructor called" << std::endl;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& obj)
{
	if (DEBUG)
		std::cout << "MutantStack Copy assignment operator called" << std::endl;
	if (this != &obj)
		std::stack<T>::operator=(obj);
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return this->c.end();
}