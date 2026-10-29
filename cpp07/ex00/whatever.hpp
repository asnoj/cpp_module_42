#ifndef WHATEVER_HPP
#define WHATEVER_HPP

/**
 * @brief Swaps the values of two variables of the same type.
 *
 * @tparam T Any type that supports copy construction and assignment.
 * @param a Reference to the first variable.
 * @param b Reference to the second variable.
 */
template <typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

/**
 * @brief Compares two values and returns the smallest one.
 *        If both values are equal, returns the second one (b).
 *
 * @tparam T Any type supporting the '<' comparison operator.
 * @param a Const reference to the first value.
 * @param b Const reference to the second value.
 * @return Const reference to the smallest value (or b if equal).
 */
template <typename T>
T const &min(T const &a, T const &b)
{
	return (a < b) ? a : b;
}

/**
 * @brief Compares two values and returns the greatest one.
 *        If both values are equal, returns the second one (b).
 *
 * @tparam T Any type supporting the '>' comparison operator.
 * @param a Const reference to the first value.
 * @param b Const reference to the second value.
 * @return Const reference to the greatest value (or b if equal).
 */
template <typename T>
T const &max(T const &a, T const &b)
{
	return (a > b) ? a : b;
}

#endif