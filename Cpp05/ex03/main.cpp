#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);
    AForm *form = NULL;

    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form)
    {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    form = someRandomIntern.makeForm("shrubbery creation", "Home");
    if (form)
    {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    form = someRandomIntern.makeForm("presidential pardon", "Mr X");
    if (form)
    {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    AForm *bad = someRandomIntern.makeForm("not a form", "none");
    if (bad)
        delete bad;

    return 0;
}

