/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:33:55 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/26 17:55:58 by meferraz         ###   ########.fr       */
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
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

}

void testIntArray()
{
	SEPARATOR("Array<int> test");
	Array<int> arr(5);
	for (unsigned int i = 0; i < arr.size(); ++i)
		arr[i] = i + 1;

	std::cout << "Array of integers:\n";
	std::cout << arr;
}

void testStringArray()
{
	SEPARATOR("Array<std::string> test");
	Array<std::string> strs(3);
	strs[0] = "Hello";
	strs[1] = "Template";
	strs[2] = "World";

	std::cout << "Array of strings:\n";
	std::cout << strs;
}

void testEmptyArray()
{
	SEPARATOR("Empty array test");
	Array<float> empty;
	std::cout << "Size of empty array: " << empty.size() << std::endl;
	try
	{
		std::cout << empty[0];
	} catch (const std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
}

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
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
}

void testLargeArray()
{
	SEPARATOR("Large array test (100000 elements)");
	Array<int> large(100000);
	for (unsigned int i = 0; i < large.size(); ++i)
		large[i] = i;

	std::cout << "First 5 elements:\n";
	for (unsigned int i = 0; i < 5; ++i)
		std::cout << large[i] << " ";
	std::cout << "\nLast 5 elements:\n";
	for (unsigned int i = large.size() - 5; i < large.size(); ++i)
		std::cout << large[i] << " ";
	std::cout << std::endl;
}

void testEmptyArrayCopyAssign()
{
	SEPARATOR("Copy and assign empty arrays test");
	Array<int> empty1;
	Array<int> empty2(empty1);
	Array<int> empty3;
	empty3 = empty1;

	std::cout << "Empty1 size: " << empty1.size() << std::endl;
	std::cout << "Empty2 size (copy): " << empty2.size() << std::endl;
	std::cout << "Empty3 size (assigned): " << empty3.size() << std::endl;
}

struct NoDefault
{
	int value;
	NoDefault(int v) : value(v) {}

};

void testCustomType()
{
	SEPARATOR("Custom type (no default constructor) test");

	// This test is intentionally empty because Array requires
	// T to be default-constructible for construction with size n.
	// Uncommenting the following line will cause compilation error:

	// Array<NoDefault> arr(3);
}

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
		std::cout << "Accessing const array element: " << constArr[1] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
}
