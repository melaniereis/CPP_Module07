/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:59:16 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/26 17:33:29 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"
#include "../inc/ansi.h"

template <typename T>
Array<T>::Array() : _data(0), _size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	if (n == 0)
		_data = 0;
	else
		_data = new T[n]();
}

template <typename T>
Array<T>::Array(const Array &other)
{
	_data = 0; // Initialize _data to avoid dangling pointer
	*this = other;
}

template <typename T>
Array<T>::~Array()
{
	if (_data)
		delete[] _data;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		if (_size != other.size())
		{
			if (_data != 0)
				delete[] _data;
			_size = other.size();
			_data = ((_size == 0) ? 0 : new T[_size]());
			for (unsigned int i = 0; i < _size; ++i)
			_data[i] = other[i];
		}
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (_size == 0)
		throw EmptyArrayException();
	if (index >= _size)
		throw IndexOutOfBoundsException();
	return _data[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (_size == 0)
		throw EmptyArrayException();
	if (index >= _size)
		throw IndexOutOfBoundsException();
	return _data[index];
}

template <typename T>
const char* Array<T>::IndexOutOfBoundsException::what() const throw()
{
	return "Index out of bounds";
}

template <typename T>
const char* Array<T>::EmptyArrayException::what() const throw()
{
	return "Array is empty";
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &array)
{
	os << GRN << "📋 Array size: "  << RESET << array.size()
		<< MAG << "\nElements: " << RESET;
	for (unsigned int i = 0; i < array.size(); ++i)
		os << array[i] << " ";
	os << std::endl;
	return os;
}
