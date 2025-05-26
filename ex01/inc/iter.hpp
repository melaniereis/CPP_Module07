/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 10:42:57 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/26 15:39:43 by meferraz         ###   ########.fr       */
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
		(*f)(array[i]);
}

template <typename T>
void printElementOfArray(const T &element)
{
	std::cout << YEL << element << RESET << " * ";
}

