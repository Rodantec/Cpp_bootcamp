#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
public:
    Span(unsigned int n);
    Span(const Span &other);
    ~Span();

    Span &operator=(const Span &other);

    void addNumber(int value);

    template <typename InputIt>
    void addNumbers(InputIt first, InputIt last)
    {
        while (first != last)
        {
            if (_data.size() >= _N)
                throw std::runtime_error("Span: full");
            _data.push_back(*first);
            ++first;
        }
    }

    int shortestSpan() const;
    int longestSpan() const;

private:
    unsigned int _N;
    std::vector<int> _data;
    Span();
};

#endif
