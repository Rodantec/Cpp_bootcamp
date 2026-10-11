#include <iostream>
#include "MutantStack.hpp"
#include <stack>

int main()
{
    MutantStack<int> m;

    m.push(10);
    m.push(20);
    m.push(30);

    std::cout << "top: " << m.top() << std::endl; 
    m.pop();
    std::cout << "size: " << m.size() << std::endl;

    for (MutantStack<int>::iterator it = m.begin(); it != m.end(); ++it)
        std::cout << *it << std::endl;

    std::stack<int> s(m);
    std::cout << "copied stack top: " << s.top() << std::endl;

    return 0;
}