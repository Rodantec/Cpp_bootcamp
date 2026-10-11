#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5)
{

}
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{   

}
PresidentialPardonForm::~PresidentialPardonForm()
{

}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy)
{ 

}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    AForm::operator=(copy);
    return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    AForm::execute(executor);
    std::cout << getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}