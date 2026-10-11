#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45)
{

}
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy)
{   

}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    AForm::operator=(copy);
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    AForm::execute(executor);
    static bool seeded = false;
    if (!seeded)
    {
        std::srand(static_cast<unsigned int>(std::time(NULL)));
        seeded = true;
    }
    std::cout << "Bzzzzzz... Bzzzzzz... Bzzzzzz..." << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << getName() << " has been robotomized successfully 50% of the time." << std::endl;
    else
        std::cout << getName() << " robotomy failed." << std::endl;
}