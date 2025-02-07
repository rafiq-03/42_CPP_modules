/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:00:15 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/02/06 17:59:48 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
Array<T>::Array(void):a(new T[0]), size(0)
{
	if (DEBUG)
		std::cout << "Array Default constructor called" << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n):a(new T[n]), size(n)
{
	if (DEBUG)
		std::cout << "Array Parametrized constructor called" << std::endl;
}

template<typename T>
Array<T>::~Array(void)
{
	if (DEBUG)
		std::cout << "Array Destructor called" << std::endl;
	delete[] a;// delete array
}

template<typename T>
Array<T>::Array(const Array& obj)
{
	if (DEBUG)
		std::cout << "Array Copy constructor called" << std::endl;
	this->a = new T[obj.size];
	for(size_t i = 0; i < obj.size; i++)
		this->a[i] = obj.a[i];
}
template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& obj)
{
	if (DEBUG)
		std::cout << "Array Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		delete[] a;
		this->a = new T[obj.size];
		for(size_t i = 0; i < obj.size; i++)
			this->a[i] = obj.a[i];
	}
	return (*this);
}

template<typename T>
T&	Array<T>::operator[](unsigned int index)
{
	if (index >= size)
		throw std::out_of_range("out of range");
	return a[index];
}
