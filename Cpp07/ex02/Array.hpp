#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array
{
public:
	Array();
	explicit Array(unsigned int n);
	Array(const Array &other);
	~Array();
	Array &operator=(const Array &other);
	size_t size() const;
	T &operator[](size_t index);
	const T &operator[](size_t index) const;

private:
	T *m_data;
	size_t m_size;
};

#include "Array.tpp"

#endif
