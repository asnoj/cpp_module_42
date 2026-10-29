#include <iostream>
#include <string>
#include "whatever.hpp"

int main(void)
{
	// Standard subject tests
	int a = 2;
	int b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

	// Additional test: verifying equality behavior (should return second parameter)
	std::cout << "\n--- Additional Equality Test ---" << std::endl;
	int x = 42;
	int y = 42;
	std::cout << "Address of x: " << &x << std::endl;
	std::cout << "Address of y: " << &y << std::endl;
	std::cout << "Address returned by min(x, y): " << &::min(x, y) << std::endl;
	std::cout << "Address returned by max(x, y): " << &::max(x, y) << std::endl;

	return 0;
}