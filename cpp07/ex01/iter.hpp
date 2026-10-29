#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

/**
 * @brief Iterates over an array and applies a function to each element.
 *
 * Works for both non-const and const arrays, as well as functions accepting
 * non-const or const references.
 *
 * @tparam T Type of the array elements.
 * @tparam F Type of the function/callable.
 * @param array Pointer to the first element of the array.
 * @param length Size of the array (passed as a const value).
 * @param func Function to apply on each element.
 */
template <typename T, typename F>
void iter(T *array, std::size_t const length, F func)
{
	if (!array)
		return;
	for (std::size_t i = 0; i < length; ++i)
	{
		func(array[i]);
	}
}

#endif