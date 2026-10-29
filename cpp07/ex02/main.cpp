#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750

int main(int, char **)
{
	// Basic functionality tests
	std::cout << "--- Test 1: Empty Array ---" << std::endl;
	Array<int> emptyArray;
	std::cout << "Empty array size: " << emptyArray.size() << std::endl;

	std::cout << "\n--- Test 2: Int Array Initialization & Modification ---" << std::endl;
	Array<int> intArray(5);
	std::cout << "Int array size: " << intArray.size() << std::endl;
	std::cout << "Initial values (default initialized): ";
	for (unsigned int i = 0; i < intArray.size(); ++i)
	{
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;

	for (unsigned int i = 0; i < intArray.size(); ++i)
	{
		intArray[i] = (i + 1) * 10;
	}

	std::cout << "Modified values: ";
	for (unsigned int i = 0; i < intArray.size(); ++i)
	{
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "\n--- Test 3: Deep Copy Isolation ---" << std::endl;
	Array<int> copyArray(intArray);
	copyArray[0] = 999;
	std::cout << "Original intArray[0]: " << intArray[0] << " (should be 10)" << std::endl;
	std::cout << "Copy copyArray[0]: " << copyArray[0] << " (should be 999)" << std::endl;

	std::cout << "\n--- Test 4: Exception Handling (Out of Bounds) ---" << std::endl;
	try
	{
		std::cout << "Accessing index 10 in size 5 array..." << std::endl;
		std::cout << intArray[10] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "Accessing negative index (cast to unsigned)..." << std::endl;
		std::cout << intArray[-1] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 5: Complex Types (std::string) ---" << std::endl;
	Array<std::string> strArray(3);
	strArray[0] = "Ecole";
	strArray[1] = "42";
	strArray[2] = "proute";
	for (unsigned int i = 0; i < strArray.size(); ++i)
	{
		std::cout << strArray[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}