#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
int main()
{
    try
    {
		std::srand(std::time(NULL));
        Bureaucrat alice("Alice", 1);

        PresidentialPardonForm pardon("Prisoner");
        RobotomyRequestForm robot("Bender");
        ShrubberyCreationForm shrub("garden");

        alice.signForm(pardon);
        alice.signForm(robot);
        alice.signForm(shrub);

        alice.executeForm(pardon);
        alice.executeForm(robot);
        alice.executeForm(shrub);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bob("Bob", 50);
        PresidentialPardonForm pardon("Prisoner");

        bob.signForm(pardon);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat charlie("Charlie", 50);
        PresidentialPardonForm pardon("Prisoner");

        charlie.executeForm(pardon);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat dave("Dave", 50);
        PresidentialPardonForm pardon("Prisoner");

        dave.signForm(pardon);
        dave.executeForm(pardon);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}