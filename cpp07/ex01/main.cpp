#include <iostream>
#include <string>
#include "iter.hpp"

// Test function: modifies non-const elements
template <typename T>
void increment(T &x)
{
	x += 1;
}

// Test function: print element (read-only)
template <typename T>
void printElement(T const &x)
{
	std::cout << x << " ";
}

int main(void)
{
	std::cout << "--- Test 1: Non-const int array ---" << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	std::size_t intLen = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Original array: ";
	::iter(intArray, intLen, printElement<int>);
	std::cout << std::endl;

	// Mutate elements
	::iter(intArray, intLen, increment<int>);

	std::cout << "After increment: ";
	::iter(intArray, intLen, printElement<int>);
	std::cout << std::endl;

	std::cout << "\n--- Test 2: Const std::string array ---" << std::endl;
	const std::string strArray[] = {"42", "proute", "galbiche", "C++"};
	std::size_t strLen = sizeof(strArray) / sizeof(strArray[0]);

	std::cout << "Const string array: ";
	::iter(strArray, strLen, printElement<std::string>);
	std::cout << std::endl;

	return 0;
}