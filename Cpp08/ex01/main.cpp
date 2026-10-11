#include <iostream>
#include "Span.hpp"
#include <cstdlib>
#include <vector>

int main()
{
    try
    {
        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(6);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try
    {
        Span big(10000);

        std::vector<int> v;
        for (int i = 0; i < 10000; ++i)
            v.push_back(rand());

        big.addNumbers(v.begin(), v.end());

        std::cout << big.shortestSpan() << std::endl;
        std::cout << big.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}