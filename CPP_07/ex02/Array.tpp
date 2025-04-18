/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:00:15 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/04/18 18:27:26 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
Array<T>::Array(void):_Data(new T[0]()), _size(0)
{
	if (DEBUG)
		std::cout << "Array Default constructor called" << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n):_Data(new T[n]()), _size(n)
{
	if (DEBUG)
		std::cout << "Array Parametrized constructor called" << std::endl;
}

template<typename T>
Array<T>::~Array(void)
{
	if (DEBUG)
		std::cout << "Array Destructor called" << std::endl;
	delete[] _Data;
}

template<typename T>
Array<T>::Array(const Array& obj)
{
	if (DEBUG)
		std::cout << "Array Copy constructor called" << std::endl;
	this->_size = obj._size;
	this->_Data = new T[obj._size];
	for(size_t i = 0; i < obj._size; i++)
		this->_Data[i] = obj._Data[i];
}
template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& obj)
{
	if (DEBUG)
		std::cout << "Array Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		delete[] _Data;
		this->_size = obj._size;
		this->_Data = new T[obj._size];
		for(size_t i = 0; i < obj._size; i++)
			this->_Data[i] = obj._Data[i];
	}
	return (*this);
}

template<typename T>
T&	Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Index is out of range");
	return _Data[index];
}

template<typename T>
size_t	Array<T>::size(void) const{
	return (_size);
}
