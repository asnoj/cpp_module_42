#ifndef ARRAY_TPP
#define ARRAY_TPP

/**
 * @brief Default constructor: Creates an empty array.
 */
template <typename T>
Array<T>::Array() : _elements(NULL), _size(0) {}

/**
 * @brief Constructor with size: Creates an array of n default-initialized elements.
 *
 * @param n Number of elements to allocate.
 */
template <typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n]()), _size(n) {}

/**
 * @brief Copy constructor: Performs a deep copy of the source array.
 *
 * @param src Source Array object to copy from.
 */
template <typename T>
Array<T>::Array(Array const &src) : _elements(NULL), _size(0)
{
	*this = src;
}

/**
 * @brief Assignment operator: Performs deep copy and handles self-assignment.
 *
 * @param rhs Source Array object to assign from.
 * @return Reference to current object.
 */
template <typename T>
Array<T> &Array<T>::operator=(Array const &rhs)
{
	if (this != &rhs)
	{
		delete[] _elements;
		_size = rhs._size;
		if (_size > 0)
		{
			_elements = new T[_size]();
			for (unsigned int i = 0; i < _size; ++i)
			{
				_elements[i] = rhs._elements[i];
			}
		}
		else
		{
			_elements = NULL;
		}
	}
	return *this;
}

/**
 * @brief Destructor: Releases dynamically allocated memory.
 */
template <typename T>
Array<T>::~Array()
{
	delete[] _elements;
}

/**
 * @brief Non-const subscript operator.
 *
 * @param index Index of element to access.
 * @return Reference to element at index.
 * @throw OutOfBoundsException If index is out of array bounds.
 */
template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _elements[index];
}

/**
 * @brief Const subscript operator for read-only access.
 *
 * @param index Index of element to access.
 * @return Const reference to element at index.
 * @throw OutOfBoundsException If index is out of array bounds.
 */
template <typename T>
T const &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _elements[index];
}

/**
 * @brief Returns the number of elements in the array.
 */
template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

#endif