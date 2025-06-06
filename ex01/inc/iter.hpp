/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 10:42:57 by meferraz          #+#    #+#             */
/*   Updated: 2025/06/06 21:15:34 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "ansi.h"

/**
 * Applies a given function to each element of an array.
 *
 * @tparam T The type of the elements in the array.
 * @param array A pointer to the first element of the array.
 * @param size The number of elements in the array. Must not exceed the actual array size.
 * @param f A function pointer that takes a constant reference to an element of type T and returns void.
 * @warning Undefined behavior if `size` exceeds the actual array size.
 */
template <typename T>
void iter(T *array, const size_t size, void (*f)(const T &))
{
	if (!array || size == 0 || !f)
	{
		std::cerr << RED << "Error: Invalid array, size, or function pointer." << RESET << std::endl;
		return;
	}
	for (size_t i = 0; i < size; ++i)
	{
		(*f)(array[i]);
	}
}

/**
 * Applies a given function to each element of an array, modifying the elements.
 *
 * @tparam T The type of the elements in the array.
 * @param array A pointer to the first element of the array.
 * @param size The number of elements in the array. Must not exceed the actual array size.
 * @param f A function pointer that takes a reference to an element of type T and returns void.
 * @warning Undefined behavior if `size` exceeds the actual array size.
 */
template <typename T>
void iter(T *array, const size_t size, void (*f)(T &))
{
	if (!array || size == 0 || !f)
	{
		std::cerr << RED << "Error: Invalid array, size, or function pointer." << RESET << std::endl;
		return;
	}
	for (size_t i = 0; i < size; ++i)
	{
		(*f)(array[i]);
	}
}

/**
 * Prints a given element of an array to the standard output.
 *
 * @param element A constant reference to the element to print.
 */
template <typename T>
void printElementOfArray(const T &element)
{
	std::cout << YEL << element << RESET << " * ";
}
