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

#include "../inc/whatever.hpp"

#define SEPARATOR(txt) std::cout << "\n" \
<< BWHT "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" \
<< "📄 " << BBLU << txt << BWHT "\n" \
<< "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" RESET "\n" << std::endl;

//Functions Prototype
void test_subject_case();
void test_int();
void test_string();
void test_double();
void test_char();

int main()
{
	std::cout << BGRN "\n\n📋===== SWAP, MIN, MAX W/TEMPLATES =====📋\n\n" RESET;

	test_subject_case();
	test_int();
	test_string();
	test_double();
	test_char();

	SEPARATOR("MIXED TYPE TEST (COMMENTED)")
	/*
	int i = 5;
	double d = 3.14;
	swap(i, d); // ❌ ERROR: no matching function for call to 'swap(int&, double&)'
	std::cout << min(i, d); // ❌ ERROR
	std::cout << max(i, d); // ❌ ERROR
	*/

	std::cout << BGRN "\n\n✅ All tests complete!\n\n" RESET;
	return 0;
}

void test_subject_case()
{
	SEPARATOR("SUBJECT TEST")

	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

void test_int()
{
	SEPARATOR("INT TEST")

	int a = 10;
	int b = 20;

	std::cout << BYEL "Before swap: " RESET "a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << BGRN "After swap: " RESET "a = " << a << ", b = " << b << std::endl;
	std::cout << BCYN "min(a, b): " RESET << min(a, b) << std::endl;
	std::cout << BMAG "max(a, b): " RESET << max(a, b) << std::endl;
}

void test_string()
{
	SEPARATOR("STRING TEST")

	std::string s1 = "Apple";
	std::string s2 = "Banana";

	std::cout << BYEL "Before swap: " RESET "s1 = " << s1 << ", s2 = " << s2 << std::endl;
	swap(s1, s2);
	std::cout << BGRN "After swap: " RESET "s1 = " << s1 << ", s2 = " << s2 << std::endl;
	std::cout << BCYN "min(s1, s2): " RESET << min(s1, s2) << std::endl;
	std::cout << BMAG "max(s1, s2): " RESET << max(s1, s2) << std::endl;
}

void test_double()
{
	SEPARATOR("DOUBLE TEST")

	double x = 3.14;
	double y = 2.71;

	std::cout << BYEL "Before swap: " RESET "x = " << x << ", y = " << y << std::endl;
	swap(x, y);
	std::cout << BGRN "After swap: " RESET "x = " << x << ", y = " << y << std::endl;
	std::cout << BCYN "min(x, y): " RESET << min(x, y) << std::endl;
	std::cout << BMAG "max(x, y): " RESET << max(x, y) << std::endl;
}

void test_char()
{
	SEPARATOR("CHAR TEST")

	char c1 = 'Z';
	char c2 = 'A';

	std::cout << BYEL "Before swap: " RESET "c1 = " << c1 << ", c2 = " << c2 << std::endl;
	swap(c1, c2);
	std::cout << BGRN "After swap: " RESET "c1 = " << c1 << ", c2 = " << c2 << std::endl;
	std::cout << BCYN "min(c1, c2): " RESET << min(c1, c2) << std::endl;
	std::cout << BMAG "max(c1, c2): " RESET << max(c1, c2) << std::endl;
}
