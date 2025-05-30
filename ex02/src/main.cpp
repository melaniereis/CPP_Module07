/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:33:55 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/30 21:33:27 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"
#include "../inc/ansi.h"

#define SEPARATOR(txt) std::cout << "\n"                                              \
                                 << BWHT "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"     \
                                 << "📄 " << BBLU << txt << BWHT "\n"                 \
                                 << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" RESET "\n" \
                                 << std::endl;

// ─────────────────────────────────────────────────────────────
// 📌 Funções auxiliares - Protótipos
// ─────────────────────────────────────────────────────────────

void testIntArray();
void testCopyConstructor();
void testAssignmentOperator();
void testOperatorIndex();
void testOutOfBounds();
void testStringArray();
void testEmptyArray();
void testLargeArray();
void testEmptyArrayCopyAssign();
void testCustomType();
void testConstCorrectness();

// ─────────────────────────────────────────────────────────────
// 🚀 main()
// ─────────────────────────────────────────────────────────────

/**
 * main function executes a series of tests on the Array class template.
 *
 * It evaluates the functionality of the Array class by calling several test
 * functions, each targeting specific features such as copy constructor,
 * assignment operator, index operator, handling of integer and string arrays,
 * and managing edge cases like empty arrays, out-of-bounds access, and large
 * arrays. Additionally, it tests custom types and verifies const correctness.
 *
 * Exceptions are caught and handled to ensure that memory allocation failures
 * and unhandled exceptions are reported.
 *
 * The program prints the results of the tests and exits with a return code of 0.
 */
int main()
{
	std::cout << BGRN "\n\n📋===== CLASS W/TEMPLATES =====📋\n\n" RESET;

	try
	{
		testCopyConstructor();
		testAssignmentOperator();
		testOperatorIndex();
		testIntArray();
		testStringArray();
		testEmptyArray();
		testEmptyArrayCopyAssign();
		testOutOfBounds();
		testLargeArray();
		testCustomType();
		testConstCorrectness();
	} catch (const std::bad_alloc &e)
	{
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
	} catch (const std::exception &e)
	{
		std::cerr << "Unhandled exception: " << e.what() << std::endl;
	}

	std::cout << BGRN "\n\n✅ All tests complete!\n\n" RESET;
	return 0;
}

// ─────────────────────────────────────────────────────────────
// 🔧 Funções auxiliares - Implementação
// ─────────────────────────────────────────────────────────────

/**
 * testCopyConstructor tests the copy constructor of the Array class.
 *
 * It creates an original array, then creates a copy of it using the copy
 * constructor. The contents of both arrays are printed to verify that the copy
 * contains the same elements in the same order as the original.
 */
void testCopyConstructor()
{
	SEPARATOR("Copy constructor test");
	Array<int> original(3);
	for (unsigned int i = 0; i < original.size(); ++i)
		original[i] = i + 1;

	Array<int> copy(original);
	std::cout << "Original Array:\n";
	std::cout << original;
	std::cout << "Copied Array:\n";
	std::cout << copy;
}

/**
 * Tests the assignment operator of the Array class.
 *
 * This test initializes an array 'a' with integer values and assigns it to
 * another array 'b' using the assignment operator. It then prints both
 * arrays to verify that 'b' contains the same elements as 'a' in the same order.
 */
void testAssignmentOperator()
{
	SEPARATOR("Assignment operator test");
	Array<int> a(4);
	for (unsigned int i = 0; i < a.size(); ++i)
		a[i] = i * 5;

	Array<int> b;
	b = a;
	std::cout << "Original Array:\n";
	std::cout << a;
	std::cout << "Copied Array:\n";
	std::cout << b;
}

/**
 * Tests the index operator of the Array class.
 *
 * This test initializes an array of 5 elements and prints it out.
 * It then changes the third element and prints the array out again.
 * Additionally, it tests the read-only const version of the index operator
 * by attempting to access an element and then attempting to access an out-of-bounds
 * index, which should throw an exception.
 */
void testOperatorIndex()
{
	SEPARATOR("Operator[] test");
	Array<int> arr(5);
	for (unsigned int i = 0; i < arr.size(); ++i)
		arr[i] = i + 1;

	std::cout << "Array before modification:\n";
	std::cout << arr;
	arr[2] = 42; // Change the third element
	std::cout << "After modifying the third element:\n";
	std::cout << arr;
	std::cout << std::endl;

	SEPARATOR("READ-ONLY test");
	const Array<int> readOnlyArr(3);
	std::cout << readOnlyArr;
	try
	{
		std::cout << "Trying to access an element: " << readOnlyArr[1] << std::endl;
		std::cout << readOnlyArr[0] << std::endl; // This should work

		// Attempting to access an out-of-bounds index
		// This should throw an exception
		std::cout << "Trying to access an element out of bounds: " << std::endl;
		std::cout << readOnlyArr[5] << std::endl; // This should throw an exception
	} catch (const std::exception &e)
	{
		std::cerr << RED << "Caught exception: " << e.what() << RESET << std::endl;
	}

}

/**
 * Tests the Array class with an array of integers.
 *
 * This test initializes an array of 5 elements, assigns each element a value
 * from 1 to 5, and prints out the array to verify that the elements are
 * properly stored and retrieved.
 */
void testIntArray()
{
	SEPARATOR("Array<int> test");
	Array<int> arr(5);
	for (unsigned int i = 0; i < arr.size(); ++i)
		arr[i] = i + 1;

	std::cout << BYEL << "Array of integers:\n" << RESET;
	std::cout << arr;
}

/**
 * Tests the Array class with an array of strings.
 *
 * This test initializes an array of 3 elements, assigns each element a string
 * value, and prints out the array to verify that the elements are properly
 * stored and retrieved.
 */
void testStringArray()
{
	SEPARATOR("Array<std::string> test");
	Array<std::string> strs(3);
	strs[0] = "Hello";
	strs[1] = "Template";
	strs[2] = "World";

	std::cout << BYEL << "Array of strings:\n" << RESET;
	std::cout << strs;
}

/**
 * testEmptyArray tests the Array class with an empty array.
 *
 * This test initializes an empty array and verifies that its size is 0.
 * It then attempts to access an element in the array, which should throw
 * an exception.
 */
void testEmptyArray()
{
	SEPARATOR("Empty array test");
	Array<float> empty;
	std::cout << "Size of empty array: " << empty.size() << std::endl;
	try
	{
		std::cout << empty[0];
	} catch (const std::exception &e) {
		std::cerr << RED << "Caught exception: " << e.what() << RESET << std::endl;
	}
}

/**
 * testOutOfBounds tests the Array class with an out of bounds access.
 *
 * This test initializes an array of 2 elements, assigns each element an integer
 * value, and attempts to access an element at index 10, which should throw
 * an exception.
 */
void testOutOfBounds()
{
	SEPARATOR("Out of bounds access");
	Array<int> a(2);
	a[0] = 1;
	a[1] = 2;

	try
	{
		std::cout << a[10] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Caught exception: " << e.what() << RESET << std::endl;
	}
}

/**
 * Tests the Array class with a large array.
 *
 * This test initializes an array with 100,000 elements, assigns each element
 * its index value, and prints the first and last 5 elements to verify that
 * the array is properly populated and accessed.
 */
void testLargeArray()
{
	SEPARATOR("Large array test (100000 elements)");
	Array<int> large(100000);
	for (unsigned int i = 0; i < large.size(); ++i)
		large[i] = i;

	std::cout << "First 5 elements:\n";
	for (unsigned int i = 0; i < 5; ++i)
		std::cout << BYEL << large[i] << " " << RESET;
	std::cout << "\nLast 5 elements:\n";
	for (unsigned int i = large.size() - 5; i < large.size(); ++i)
		std::cout << BBLU << large[i] << " " << RESET;
	std::cout << std::endl;
}

/**
 * Tests copy construction and assignment of empty arrays.
 *
 * This test creates an empty array and verifies that a copy
 * constructor and an assignment operator can correctly handle
 * empty arrays without errors. It checks that the sizes of the
 * original, copied, and assigned arrays remain zero.
 */
void testEmptyArrayCopyAssign()
{
	SEPARATOR("Copy and assign empty arrays test");
	Array<int> empty1;
	Array<int> empty2(empty1);
	Array<int> empty3;
	empty3 = empty1;

	std::cout << "Empty1 size: " << YEL
			<< empty1.size() << RESET << std::endl;
	std::cout << "Empty2 size (copy): " << YEL
			<< empty2.size() << RESET << std::endl;
	std::cout << "Empty3 size (assigned): " << YEL
			<< empty3.size() << RESET << std::endl;
}

struct NoDefault
{
	int value;
	NoDefault(int v) : value(v) {}

};

/**
 * Tests the Array class with a custom type that does not have a default
 * constructor. This is a negative test and should not compile if uncommented.
 *
 * This test is intentionally empty because Array requires
 * T to be default-constructible for construction with size n.
 *
 * Uncommenting the following line will cause compilation error:
 *
 * Array<NoDefault> arr(3);
 */
void testCustomType()
{
	SEPARATOR("Custom type (no default constructor) test");

	// This test is intentionally empty because Array requires
	// T to be default-constructible for construction with size n.
	// Uncommenting the following line will cause compilation error:

	// Array<NoDefault> arr(3);
}

/**
 * Const correctness test.
 *
 * This test verifies that the Array class is const correct.
 *
 * It creates a non-const array, copies it to a const array, and verifies that
 * the contents of the const array cannot be modified. It also verifies that
 * attempting to access a non-existent element of the const array throws an
 * exception.
 */
void testConstCorrectness()
{
	SEPARATOR("Const correctness test");
	Array<int> modifiable(3);
	for (unsigned int i = 0; i < modifiable.size(); ++i)
		modifiable[i] = i * 10;

	const Array<int> constArr = modifiable;
	std::cout << "Const Array contents:\n" << constArr;

	// Attempting to modify a const array should not compile
	// constArr[0] = 5; // This should give a compilation error, test in IDE

	try
	{
		std::cout << YEL << "Accessing const array element: "
		<< RESET << constArr[1] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Caught exception: "
		<< e.what() << RESET<< std::endl;
	}
}
