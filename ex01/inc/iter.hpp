/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 10:42:57 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/24 16:31:12 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "ansi.h"

template <typename T>
void iter(T *array, const size_t size, void (*f)(const T &))
{
	for (size_t i = 0; i < size; i++)
	{
		(*f)(array[i]);
	}
}

template <typename T>
void printArray(T *array)
{
	for (size_t i = 0; i < (sizeof(array) / sizeof(array[0])); i++)
	{
		std::cout << array[i] << " * ";
	}
	std::cout << std::endl;
}
