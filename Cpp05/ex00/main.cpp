#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try 
    {
        Bureaucrat a("Alice", 2);
        std::cout << a << '\n';
        a.incrementGrade();
        std::cout << a << '\n';
        a.incrementGrade();
    } 
    catch (const std::exception &e)
    {
        std::cerr << "Error " << e.what() << '\n';
    }


    try
    {
        Bureaucrat a("Rodantec", 150);
        std::cout << a << '\n';
        a.decrementGrade();
    } 
    catch (const std::exception &e)
    {
        std::cerr << "Error " << e.what() << '\n';
    }

    try
    {
        Bureaucrat c("Bob", 0);
        c.incrementGrade(); 
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error " << e.what() << '\n';
    }

    Bureaucrat d;
    std::cout << d << '\n';

    return 0;
}