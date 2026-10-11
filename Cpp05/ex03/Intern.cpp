#include "Intern.hpp"
#include <iostream>

typedef AForm *(*FormCreator)(std::string);

Intern::Intern()
{

}
Intern::Intern(const Intern &copy)
{
    (void)copy;
}
Intern &Intern::operator=(const Intern &copy)
{
    (void)copy;
    return *this;
}
Intern::~Intern()
{

}

static AForm *makeShrub(std::string target)
{
    return new ShrubberyCreationForm(target);
}

static AForm *makeRobot(std::string target)
{
    return new RobotomyRequestForm(target);
}

static AForm *makePres(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    const std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    FormCreator creators[3] = {&makeShrub, &makeRobot, &makePres};

    for (int i = 0; i < 3; ++i)
    {
        if (formName == names[i])
        {
            AForm *f = creators[i](target);
            std::cout << "Intern creates " << formName << std::endl;
            return f;
        }
    }
    std::cerr << "Intern couldn't create " << formName << " (unknown form)" << std::endl;
    return NULL;
}