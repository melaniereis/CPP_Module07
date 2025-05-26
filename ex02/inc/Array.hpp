/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:46:07 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/26 17:31:54 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		~Array();
		Array &operator=(const Array &other);

		T &operator[](unsigned int index);
		const T &operator[](unsigned int index) const;

		class IndexOutOfBoundsException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class EmptyArrayException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		unsigned int size() const;

	private:
		T *_data;
		unsigned int _size;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &array);

#include "../src/Array.tpp"
