# 🧩 CPP Module 07 - Templates

<div align="center">

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![42 School](https://img.shields.io/badge/42-School-000000?style=for-the-badge&logo=42&logoColor=white)
![Module](https://img.shields.io/badge/Module-07-blue?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)

*Mastering Generic Programming and Templates*

</div>

## 📖 Overview

**CPP Module 07** introduces the powerful world of **templates** and **generic programming** in C++. From simple function templates to complex class templates, you'll discover how to write flexible, reusable code that works with any data type while maintaining type safety and performance. This module establishes the foundation for understanding the Standard Template Library (STL).

### 🎯 Learning Objectives

- Master function template syntax and usage
- Implement class templates with complex functionality
- Understand template instantiation and compilation
- Learn template specialization techniques
- Practice generic programming principles
- Implement custom containers with templates
- Explore template metaprogramming concepts

## 💡 Key Concepts Introduced

- **Function Templates**: Generic functions that work with any type
- **Class Templates**: Generic classes for containers and data structures
- **Template Instantiation**: How templates are compiled
- **Template Parameters**: Type and non-type parameters
- **Template Specialization**: Customizing templates for specific types
- **Generic Programming**: Writing code independent of specific types
- **Type Deduction**: Automatic type inference from context

## 🔧 Template Syntax

### Function Templates
```cpp
template <typename T>
T functionName(T parameter) {
    // Generic implementation
}
```

### Class Templates
```cpp
template <typename T>
class ClassName {
    // Generic class implementation
};
```

### Template Specialization
```cpp
template <>
class ClassName<int> {
    // Specialized implementation for int
};
```

## 🚀 Exercises

### 🔄 Exercise 00: Start with a Few Functions
**Files**: `whatever.hpp`, `main.cpp`

Introduction to function templates through utility functions, demonstrating:
- Basic function template syntax
- Template type deduction
- Generic swap, min, and max operations
- Template instantiation for different types

**Function Templates Implementation**:
```cpp
/**
 * @brief Swap the values of two variables
 * @param a The first variable
 * @param b The second variable
 */
template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

/**
 * @brief Get the minimum of two variables
 * @param a The first variable
 * @param b The second variable
 * @return Reference to the smaller value
 */
template <typename T>
const T &min(const T &a, const T &b) {
    return (a < b) ? a : b;
}

/**
 * @brief Get the maximum of two variables
 * @param a The first variable
 * @param b The second variable
 * @return Reference to the larger value
 */
template <typename T>
const T &max(const T &a, const T &b) {
    return (a > b) ? a : b;
}
```

**Template Usage Examples**:
```cpp
void testInt() {
    int a = 2;
    int b = 3;

    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);  // Explicit scope resolution to avoid std::swap
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
}

void testString() {
    std::string s1 = "chaine1";
    std::string s2 = "chaine2";

    ::swap(s1, s2);
    std::cout << "s1 = " << s1 << std::endl;  // "chaine2"
    std::cout << "s2 = " << s2 << std::endl;  // "chaine1"

    std::cout << "min(s1, s2) = " << ::min(s1, s2) << std::endl;
    std::cout << "max(s1, s2) = " << ::max(s1, s2) << std::endl;
}
```

**Template Type Deduction**:
```cpp
int main() {
    int a = 42, b = 21;

    // Automatic type deduction
    ::swap(a, b);              // T deduced as int

    double x = 3.14, y = 2.71;
    ::swap(x, y);              // T deduced as double

    // Mixed types don't work - compilation error
    // ::min(a, x);            // Error: T cannot be both int and double

    return 0;
}
```

**Key Learning Points**:
- Template syntax and declaration
- Automatic type deduction
- Template instantiation process
- Scope resolution with templates
- Type consistency requirements

---

### 🔁 Exercise 01: Iter
**Files**: `iter.hpp`, `main.cpp`

Advanced function templates with function pointers, showcasing:
- Function templates with multiple parameters
- Function pointer parameters in templates
- Error handling in generic functions
- Iterator-like functionality with arrays

**Iter Function Template**:
```cpp
/**
 * Applies a given function to each element of an array.
 * @tparam T The type of the elements in the array
 * @param array A pointer to the first element of the array
 * @param size The number of elements in the array
 * @param f A function pointer that takes a const reference to T
 * @warning Undefined behavior if size exceeds actual array size
 */
template <typename T>
void iter(T *array, const size_t size, void (*f)(const T &)) {
    if (!array || size == 0 || !f) {
        std::cerr << "Error: Invalid array, size, or function pointer." << std::endl;
        return;
    }

    for (size_t i = 0; i < size; ++i) {
        (*f)(array[i]);
    }
}
```

**Function Templates for Testing**:
```cpp
// Generic print function
template <typename T>
void print(const T &element) {
    std::cout << element << " ";
}

// Generic increment function (for modifiable elements)
template <typename T>
void increment(T &element) {
    ++element;
}

// Specialized functions for specific types
template <>
void increment<std::string>(std::string &element) {
    element += "!";
}
```

**Comprehensive Usage Examples**:
```cpp
void testIntArray() {
    int numbers[] = {1, 2, 3, 4, 5};
    size_t size = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << "Original array: ";
    ::iter(numbers, size, print<int>);
    std::cout << std::endl;

    // Apply increment to each element
    ::iter(numbers, size, increment<int>);

    std::cout << "After increment: ";
    ::iter(numbers, size, print<int>);
    std::cout << std::endl;
}

void testStringArray() {
    std::string words[] = {"Hello", "World", "Template"};
    size_t size = sizeof(words) / sizeof(words[0]);

    std::cout << "String array: ";
    ::iter(words, size, print<std::string>);
    std::cout << std::endl;

    ::iter(words, size, increment<std::string>);

    std::cout << "After adding '!': ";
    ::iter(words, size, print<std::string>);
    std::cout << std::endl;
}
```

**Advanced Function Pointer Usage**:
```cpp
// Function object as parameter
template <typename T>
void iter(T *array, const size_t size, void (*f)(T &)) {
    if (!array || size == 0 || !f) return;

    for (size_t i = 0; i < size; ++i) {
        (*f)(array[i]);
    }
}

// Lambda-like functionality (C++98 compatible)
class DoubleValue {
public:
    template <typename T>
    void operator()(T &value) {
        value *= 2;
    }
};
```

**Error Handling and Edge Cases**:
```cpp
void testErrorCases() {
    int *nullArray = NULL;
    int validArray[] = {1, 2, 3};

    // Test null array
    std::cout << "Testing null array:" << std::endl;
    ::iter(nullArray, 3, print<int>);

    // Test zero size
    std::cout << "Testing zero size:" << std::endl;
    ::iter(validArray, 0, print<int>);

    // Test null function pointer
    std::cout << "Testing null function:" << std::endl;
    ::iter(validArray, 3, static_cast<void(*)(const int&)>(NULL));
}
```

**Key Learning Points**:
- Function pointers with templates
- Template parameter constraints
- Error handling in generic code
- Function template specialization
- Generic iterator patterns

---

### 📦 Exercise 02: Array
**Files**: `Array.hpp`, `Array.tpp`, `main.cpp`

Complete class template implementation with dynamic arrays, demonstrating:
- Class template syntax and implementation
- Dynamic memory management in templates
- Operator overloading in templates
- Exception handling with custom exceptions
- Template member functions

**Array Class Template Declaration**:
```cpp
template <typename T>
class Array {
public:
    Array();                                  // Default constructor
    Array(unsigned int n);                    // Parameterized constructor
    Array(const Array &other);               // Copy constructor
    ~Array();                                 // Destructor
    Array &operator=(const Array &other);    // Assignment operator

    T &operator[](unsigned int index);       // Subscript operator
    const T &operator[](unsigned int index) const;  // Const subscript

    unsigned int size() const;               // Size getter

    // Custom Exception Classes
    class IndexOutOfBoundsException : public std::exception {
    public:
        const char *what() const throw();
    };

    class EmptyArrayException : public std::exception {
    public:
        const char *what() const throw();
    };

private:
    T *_data;                                // Dynamic array
    unsigned int _size;                      // Array size
};
```

**Template Implementation (Array.tpp)**:
```cpp
/**
 * Default constructor - creates an empty array
 */
template <typename T>
Array<T>::Array() : _data(0), _size(0) {
}

/**
 * Constructor that initializes an array with specified size
 * @param n The number of elements in the array
 */
template <typename T>
Array<T>::Array(unsigned int n) : _size(n) {
    if (n == 0)
        _data = 0;
    else
        _data = new T[n]();  // Value-initialize elements
}

/**
 * Copy constructor - deep copy
 * @param other The array to copy
 */
template <typename T>
Array<T>::Array(const Array &other) {
    _data = 0;
    _size = 0;
    *this = other;  // Use assignment operator
}

/**
 * Destructor - releases allocated memory
 */
template <typename T>
Array<T>::~Array() {
    if (_data)
        delete[] _data;
}
```

**Assignment Operator with Deep Copy**:
```cpp
template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
    if (this != &other) {
        if (_size != other.size()) {
            if (_data != 0)
                delete[] _data;
            _size = other.size();
            _data = (_size == 0) ? 0 : new T[_size]();
        }

        for (unsigned int i = 0; i < _size; ++i) {
            _data[i] = other[i];
        }
    }
    return *this;
}
```

**Bounds-Checked Access Operators**:
```cpp
template <typename T>
T &Array<T>::operator[](unsigned int index) {
    if (_size == 0)
        throw EmptyArrayException();
    if (index >= _size)
        throw IndexOutOfBoundsException();
    return _data[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const {
    if (_size == 0)
        throw EmptyArrayException();
    if (index >= _size)
        throw IndexOutOfBoundsException();
    return _data[index];
}
```

**Exception Classes Implementation**:
```cpp
template <typename T>
const char *Array<T>::IndexOutOfBoundsException::what() const throw() {
    return "Index out of bounds";
}

template <typename T>
const char *Array<T>::EmptyArrayException::what() const throw() {
    return "Array is empty";
}
```

**Comprehensive Testing**:
```cpp
void testBasicOperations() {
    std::cout << "=== Basic Operations Test ===" << std::endl;

    // Test default constructor
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;

    // Test parameterized constructor
    Array<int> numbers(5);
    std::cout << "Numbers array size: " << numbers.size() << std::endl;

    // Fill array
    for (unsigned int i = 0; i < numbers.size(); ++i) {
        numbers[i] = i * 10;
    }

    // Display array
    std::cout << "Array contents: ";
    for (unsigned int i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}

void testCopyAndAssignment() {
    std::cout << "\n=== Copy and Assignment Test ===" << std::endl;

    Array<std::string> original(3);
    original[0] = "First";
    original[1] = "Second";
    original[2] = "Third";

    // Test copy constructor
    Array<std::string> copy(original);
    std::cout << "Copy size: " << copy.size() << std::endl;

    // Modify copy to test deep copy
    copy[0] = "Modified";

    std::cout << "Original[0]: " << original[0] << std::endl;  // Should be "First"
    std::cout << "Copy[0]: " << copy[0] << std::endl;         // Should be "Modified"

    // Test assignment operator
    Array<std::string> assigned;
    assigned = original;
    std::cout << "Assigned size: " << assigned.size() << std::endl;
}

void testExceptions() {
    std::cout << "\n=== Exception Handling Test ===" << std::endl;

    Array<int> empty;
    Array<int> small(2);

    try {
        std::cout << "Accessing empty array:" << std::endl;
        empty[0] = 42;  // Should throw EmptyArrayException
    } catch (const std::exception &e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "Accessing out of bounds:" << std::endl;
        small[5] = 42;  // Should throw IndexOutOfBoundsException
    } catch (const std::exception &e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }
}
```

**Advanced Template Usage**:
```cpp
void testDifferentTypes() {
    std::cout << "\n=== Different Types Test ===" << std::endl;

    // Test with built-in types
    Array<double> doubles(3);
    doubles[0] = 3.14;
    doubles[1] = 2.71;
    doubles[2] = 1.41;

    // Test with user-defined types
    Array<std::string> strings(2);
    strings[0] = "Hello";
    strings[1] = "Template";

    // Test with pointers
    Array<int*> pointers(2);
    int a = 42, b = 84;
    pointers[0] = &a;
    pointers[1] = &b;

    std::cout << "Double array: ";
    for (unsigned int i = 0; i < doubles.size(); ++i) {
        std::cout << doubles[i] << " ";
    }
    std::cout << std::endl;
}
```

**Key Learning Points**:
- Class template syntax and implementation
- Template member functions
- Dynamic memory management in templates
- Exception handling with templates
- Deep copying in template classes
- Bounds checking and safety

## 🛠️ Compilation

Each exercise includes a Makefile with standard targets:

```bash
# Compile the program
make

# Clean object files
make clean

# Clean everything
make fclean

# Recompile
make re
```

**Compilation flags**:
```bash
c++ -Wall -Wextra -Werror -std=c++98
```

## 🎮 How to Run

### Exercise 00 - Start with a Few Functions
```bash
cd ex00
make
./whatever
```

### Exercise 01 - Iter
```bash
cd ex01
make
./iter
```

### Exercise 02 - Array
```bash
cd ex02
make
./array
```

## 🧪 Testing Examples

### Function Template Test
```cpp
// Test automatic type deduction
int a = 42, b = 21;
::swap(a, b);
std::cout << "a = " << a << ", b = " << b << std::endl;  // a = 21, b = 42

// Test with different types
std::string s1 = "Hello", s2 = "World";
std::cout << "min(s1, s2) = " << ::min(s1, s2) << std::endl;  // "Hello"
```

### Iter Function Test
```cpp
int numbers[] = {1, 2, 3, 4, 5};
std::cout << "Original: ";
::iter(numbers, 5, print<int>);  // Output: 1 2 3 4 5

::iter(numbers, 5, increment<int>);
std::cout << "\nIncremented: ";
::iter(numbers, 5, print<int>);  // Output: 2 3 4 5 6
```

### Array Template Test
```cpp
Array<int> arr(5);
for (unsigned int i = 0; i < arr.size(); ++i) {
    arr[i] = i * i;  // 0, 1, 4, 9, 16
}

Array<int> copy = arr;  // Deep copy
copy[0] = 100;

std::cout << "Original[0]: " << arr[0] << std::endl;   // 0
std::cout << "Copy[0]: " << copy[0] << std::endl;      // 100
```

## 🏗️ Project Structure

```
CPP_Module07/
├── README.md
├── ex00/                    # Start with a Few Functions
│   ├── Makefile
│   ├── inc/
│   │   ├── ansi.h
│   │   └── whatever.hpp
│   └── src/
│       └── main.cpp
├── ex01/                    # Iter
│   ├── Makefile
│   ├── inc/
│   │   ├── ansi.h
│   │   └── iter.hpp
│   └── src/
│       └── main.cpp
└── ex02/                    # Array
    ├── Makefile
    ├── inc/
    │   ├── ansi.h
    │   └── Array.hpp
    └── src/
        ├── Array.tpp
        └── main.cpp
```

## 💡 Key Takeaways

1. **Generic Programming**: Writing code that works with any type
2. **Template Syntax**: Understanding function and class template declarations
3. **Type Safety**: Templates provide compile-time type checking
4. **Code Reusability**: Single template works with multiple types
5. **Template Instantiation**: Compiler generates specific versions for each type
6. **Memory Management**: Proper resource handling in template classes
7. **Exception Safety**: Error handling in generic code

## 🎯 Skills Developed

- ✅ Function template implementation and usage
- ✅ Class template design and implementation
- ✅ Template parameter handling
- ✅ Generic programming principles
- ✅ Template instantiation understanding
- ✅ Dynamic memory management in templates
- ✅ Exception handling with templates
- ✅ Template-based container design

## ⚠️ Template Best Practices

### Function Templates
- Use meaningful template parameter names (`T`, `Type`, `Element`)
- Provide clear documentation about type requirements
- Handle edge cases and null parameters
- Use const-correctness for parameters

### Class Templates
- Implement the Orthodox Canonical Form
- Provide bounds checking and validation
- Use RAII for resource management
- Create meaningful exception classes

### General Guidelines
- Keep templates simple and focused
- Avoid deep template nesting
- Provide clear error messages
- Test with multiple types

## 🔗 Template Compilation Process

1. **Template Definition**: Compiler stores template as pattern
2. **Template Instantiation**: Compiler generates specific version for each type used
3. **Code Generation**: Separate compiled code for each instantiation
4. **Linking**: All instantiations linked together

```cpp
// Template definition (not compiled yet)
template <typename T>
T add(T a, T b) { return a + b; }

// Usage triggers instantiation
int result1 = add(3, 4);        // Generates add<int>
double result2 = add(3.14, 2.0); // Generates add<double>
```

## 🔗 Common Template Pitfalls

1. **Compilation Errors**: Templates generate errors at instantiation
2. **Code Bloat**: Each type creates separate compiled code
3. **Debugging Difficulty**: Template error messages can be cryptic
4. **Compilation Time**: Templates increase compilation time
5. **Type Requirements**: Templates assume certain operations exist

## 🔗 Template vs. Alternatives

### Templates vs. Function Overloading
- **Templates**: One definition, multiple instantiations
- **Overloading**: Multiple definitions, manual maintenance

### Templates vs. Inheritance
- **Templates**: Compile-time polymorphism, type-safe
- **Inheritance**: Runtime polymorphism, dynamic behavior

### Templates vs. Macros
- **Templates**: Type-safe, C++-aware, debuggable
- **Macros**: Text replacement, error-prone, C-style

## 🔗 Next Steps

After mastering Module 07, you'll be ready to tackle:
- **Module 08**: STL containers and iterators
- **Module 09**: Advanced STL algorithms and performance
- **Advanced Templates**: Specialization, metaprogramming, SFINAE

---

<div align="center">

*"Templates are not just about code reuse, they're about expressing algorithms independently of data types."*

**Module 07 Complete** ✨ | **Previous**: [← Module 06](../CPP_Module06/README.md) | **Next**: [Module 08 →](../CPP_Module08/README.md)

</div>
