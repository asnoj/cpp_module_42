#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>
#include <stdexcept>

template <typename T>
class Array
{
private:
	T *_elements;
	unsigned int _size;

public:
	// Orthodox Canonical Form
	Array();
	Array(unsigned int n);
	Array(Array const &src);
	Array &operator=(Array const &rhs);
	~Array();

	// Subscript operators
	T &operator[](unsigned int index);
	T const &operator[](unsigned int index) const;

	// Member functions
	unsigned int size() const;

	// Custom exception for out-of-bounds access
	class OutOfBoundsException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Array: Index out of bounds";
		}
	};
};

#include "Array.tpp"

#endif