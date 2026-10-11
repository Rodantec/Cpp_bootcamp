#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137)
{

}
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy)
{

}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    AForm::operator=(copy);
    return *this;
}   

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    AForm::execute(executor);
    std::string filename = getName() + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (!file)
    {
        std::cerr << "Error: Could not create file." << std::endl;
        return;
    }
    file << "           &&\n"
        "          &&&\n"
        "         &&&&&\n"
        "        &&&&&&&\n"
        "       &&&&&&&&&\n"
        "      &&&&&&&&&&&\n"
        "           ||\n"
        "           ||\n"
        "           ||\n"
        "           ||\n";
    file.close();
    std::cout << filename << " created with an ASCII tree." << std::endl;
}