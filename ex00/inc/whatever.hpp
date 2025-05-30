/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 10:23:28 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/30 21:16:45 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ansi.h"

/**
 * @brief Swap the values of two variables
 *
 * Swaps the values of two variables of type T.
 *
 * @param a The first variable
 * @param b The second variable
 */
template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

/**
 * @brief Get the minimum of two variables
 *
 * Returns a reference to the smaller of the two variables.
 *
 * @param a The first variable
 * @param b The second variable
 * @return A reference to the smaller variable
 */
template <typename T>
T &min(T &a, T &b)
{
	return (a < b ? a : b);
}

/**
 * @brief Get the maximum of two variables
 *
 * Returns a reference to the larger of the two variables.
 *
 * @param a The first variable
 * @param b The second variable
 * @return A reference to the larger variable
 */
template <typename T>
T &max(T &a, T &b)
{
	return (a > b ? a : b);
}
