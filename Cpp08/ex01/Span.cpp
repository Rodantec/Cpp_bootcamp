#include "Span.hpp"
#include <limits>

Span::Span(unsigned int n): _N(n)
{
}

Span::~Span()
{
}

Span::Span(const Span &other): _N(other._N), _data(other._data)
{
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _N = other._N;
        _data = other._data;
    }
    return *this;
}

void Span::addNumber(int value)
{
    if (_data.size() >= _N)
        throw std::runtime_error("Span: full");
    _data.push_back(value);
}

int Span::shortestSpan() const
{
    if (_data.size() < 2)
        throw std::runtime_error("Span: not enough elements");
    std::vector<int> tmp = _data;
    std::sort(tmp.begin(), tmp.end());
    int minDiff = std::numeric_limits<int>::max();
    for (size_t i = 1; i < tmp.size(); ++i)
    {
        int diff = tmp[i] - tmp[i - 1];
        if (diff < minDiff)
            minDiff = diff;
    }
    return minDiff;
}

int Span::longestSpan() const
{
    if (_data.size() < 2)
        throw std::runtime_error("Span: not enough elements");
    std::vector<int> tmp = _data;
    std::sort(tmp.begin(), tmp.end());
    return tmp.back() - tmp.front();
}
