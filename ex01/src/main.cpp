/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:33:55 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/26 16:57:41 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/iter.hpp"

#define SEPARATOR(txt) std::cout << "\n"                                              \
								 << BWHT "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"     \
								 << "📄 " << BBLU << txt << BWHT "\n"                 \
								 << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" RESET "\n" \
								 << std::endl;

int main()
{
	std::cout << BGRN "\n\n📋===== FUNCTIONS W/TEMPLATES =====📋\n\n" RESET;

	SEPARATOR("Test with int array")
	int intArray[] = {1, 2, 3, 4, 5};
	std::cout << " * ";
	iter(intArray, 5, printElementOfArray<int>);
	std::cout << std::endl;

	SEPARATOR("Test with float array")
	float floatArray[] = {1.1f, 2.2f, 3.3f};
	std::cout << " * ";
	iter(floatArray, 3, printElementOfArray<float>);
	std::cout << std::endl;

	SEPARATOR("Test with std::string array")
	std::cout << " * ";
	std::string strArray[] = {"42", "Porto", "Piscine", "C++"};
	iter(strArray, 4, printElementOfArray<std::string>);
	std::cout << std::endl;

	std::cout << BGRN "\n\n✅ All tests complete!\n\n" RESET;
	return 0;
}
