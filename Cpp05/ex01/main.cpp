#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try
    {
        Form form("Promotion Request", 75, 50);
        std::cout << form << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Form invalid("Invalid", 0, 50);
        std::cout << invalid << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Form invalid("Invalid", 50, 151);
        std::cout << invalid << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat rodantec("rodantec", 50);
        Form form("Promotion Request", 75, 50);
        rodantec.signForm(form);
        std::cout << form << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bob("Bob", 100);
        Form form("Promotion Request", 50, 25);
        bob.signForm(form);
        std::cout << form << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat jonathe("jonathe", 50);
        Form form("Promotion Request", 75, 50);
        jonathe.signForm(form);

        std::cout << form << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}