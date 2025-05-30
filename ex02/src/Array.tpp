/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:59:16 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/30 21:22:52 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"
#include "../inc/ansi.h"

/**
 * Default constructor. Initializes an empty array.
 *
 * @tparam T The type of elements in the array.
 */
template <typename T>
Array<T>::Array() : _data(0), _size(0)
{}

/**
 * Constructor that initializes an array with the specified size.
 * Allocates memory for the elements, initializing them to their default values.
 *
 * @tparam T The type of elements in the array.
 * @param n The number of elements in the array.
 */
template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	if (n == 0)
		_data = 0;
	else
		_data = new T[n]();
}

/**
 * Copy constructor. Initializes an array with the same size and elements as
 * the given array.
 *
 * @param other The array to copy.
 */
template <typename T>
Array<T>::Array(const Array &other)
{
	_data = 0; // Initialize _data to avoid dangling pointer
	*this = other;
}

/**
 * Destructor. Releases the memory allocated by the array.
 *
 * If the array is empty (i.e. size is 0), does nothing.
 */
template <typename T>
Array<T>::~Array()
{
	if (_data)
		delete[] _data;
}

/**
 * Assignment operator. Copies the contents of another array into this one.
 * If the sizes differ, reallocates memory for the new size.
 *
 * @param other The array to copy.
 * @return A reference to this array.
 */
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

/**
 * Access operator. Returns a reference to the element at the specified index.
 * Throws an exception if the index is out of bounds or if the array is empty.
 *
 * @param index The index of the element to access.
 * @return A reference to the element at the specified index.
 */
template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (_size == 0)
		throw EmptyArrayException();
	if (index >= _size)
		throw IndexOutOfBoundsException();
	return _data[index];
}

/**
 * Const access operator. Returns a const reference to the element at the
 * specified index. Throws an exception if the index is out of bounds or if
 * the array is empty.
 *
 * @param index The index of the element to access.
 * @return A const reference to the element at the specified index.
 */
template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (_size == 0)
		throw EmptyArrayException();
	if (index >= _size)
		throw IndexOutOfBoundsException();
	return _data[index];
}

/**
 * Returns a C-style string describing the exception.
 *
 * @return A C-style string with the error message.
 */
template <typename T>
const char* Array<T>::IndexOutOfBoundsException::what() const throw()
{
	return "Index out of bounds";
}

/**
 * Returns a C-style string describing the exception.
 *
 * This exception is thrown when trying to access an element of an empty array.
 *
 * @return A C-style string with the error message.
 */
template <typename T>
const char* Array<T>::EmptyArrayException::what() const throw()
{
	return "Array is empty";
}

/**
 * Returns the number of elements in the array.
 *
 * @return The number of elements in the array.
 */
template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

/**
 * Overloaded output operator for the Array class.
 * Prints the size and elements of the array to the output stream.
 *
 * @param os The output stream to write to.
 * @param array The array to print.
 * @return The output stream after writing the array.
 */
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
