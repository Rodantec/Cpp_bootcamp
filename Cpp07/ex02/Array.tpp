template <typename T>
Array<T>::Array() : m_data(0), m_size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : m_data(0), m_size(n)
{
	if (m_size == 0)
		return;
	m_data = new T[m_size]();
}

template <typename T>
Array<T>::Array(const Array &other) : m_data(0), m_size(other.m_size)
{
	if (m_size == 0)
		return;
	m_data = new T[m_size]();
	for (size_t i = 0; i < m_size; ++i)
		m_data[i] = other.m_data[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] m_data;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this == &other)
		return *this;
	T *newData = 0;
	if (other.m_size != 0)
	{
		newData = new T[other.m_size]();
		for (size_t i = 0; i < other.m_size; ++i)
			newData[i] = other.m_data[i];
	}
	delete[] m_data;
	m_data = newData;
	m_size = other.m_size;
	return *this;
}

template <typename T>
size_t Array<T>::size() const
{
	return m_size;
}

template <typename T>
T &Array<T>::operator[](size_t index)
{
	if (index >= m_size)
		throw std::out_of_range("Array index out of range");
	return m_data[index];
}

template <typename T>
const T &Array<T>::operator[](size_t index) const
{
	if (index >= m_size)
		throw std::out_of_range("Array index out of range");
	return m_data[index];
}
