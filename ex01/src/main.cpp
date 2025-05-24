/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:33:55 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/24 08:07:36 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/iter.hpp"

#define SEPARATOR(txt) std::cout << "\n" \
<< BWHT "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" \
<< "📄 " << BBLU << txt << BWHT "\n" \
<< "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" RESET "\n" << std::endl;

//Functions Prototype
void test_subject_case();

int main()
{
	std::cout << BGRN "\n\n📋===== SWAP, MIN, MAX W/TEMPLATES =====📋\n\n" RESET;


	std::cout << BGRN "\n\n✅ All tests complete!\n\n" RESET;
	return 0;
}
