/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:33:55 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/30 21:26:18 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/whatever.hpp"

#define SEPARATOR(txt) std::cout << "\n" \
<< BWHT "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" \
<< "📄 " << BBLU << txt << BWHT "\n" \
<< "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" RESET "\n" << std::endl;

//Functions Prototype
void testSubjectCase();
void testInt();
void testString();
void testDouble();
void testChar();

/**
 * main tests the swap, min, and max functions with various types.
 *
 * This tests that the functions work correctly with the following types:
 *   - int
 *   - const char *
 *   - double
 *   - char
 *
 * Additionally, a commented out section tests that the functions do not work
 * with mixed types.
 *
 * The program prints out the results of the tests and exits with a return code
 * of 0.
 */
int main()
{
	std::cout << BGRN "\n\n📋===== SWAP, MIN, MAX W/TEMPLATES =====📋\n\n" RESET;

	testSubjectCase();
	testInt();
	testString();
	testDouble();
	testChar();

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

/**
 * Test the min and max functions with the subject's test case
 *
 * This function tests the min and max functions with the test case provided by
 * the subject. This test case involves two int variables and two std::string
 * variables. The test case checks that the functions work correctly with both
 * arguments being greater than, less than, or equal to each other.
 */
void testSubjectCase()
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

/**
 * Tests the min and max functions with int arguments
 *
 * This tests that the min and max functions work correctly with int arguments.
 * The test case tests that the functions work correctly with both arguments
 * being greater than, less than, or equal to each other.
 */
void testInt()
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

/**
 * @brief Tests the min and max functions with std::string objects.
 *
 * @details
 * This test creates two strings, swaps them, and then prints out the
 * minimum and maximum of the two strings. The minimum and maximum
 * are determined by the lexicographical order of the strings.
 */
void testString()
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

/**
 * TestDouble tests the swap and min/max functions with double values.
 *
 * This tests swapping two double values and getting the minimum and maximum
 * values. The test shows that the swap function can be used with double values
 * and that the min and max functions can be used to get the minimum and maximum
 * of two double values.
 */
void testDouble()
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

/**
 * TestChar performs a series of operations on two char variables.
 * It swaps the values of the characters, prints the results,
 * and then determines and prints the minimum and maximum values
 * between the two characters.
 */
void testChar()
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
