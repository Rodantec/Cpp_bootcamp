#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{

}

Bureaucrat::~Bureaucrat()
{

}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    if (_grade <= 1)
        throw GradeTooHighException();
    else
        _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade >= 150)
        throw GradeTooLowException();
    else
        _grade++;
}

std::string Bureaucrat::getName() const
{
    return _name ;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high to sign!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low to sign!";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &copy)
{
    out << "Bureaucrat " << copy.getName() << ", grade: " << copy.getGrade();
    return out;
}

void Bureaucrat::signForm(AForm &form)
{
    try {
        form.beSigned(*this);
        std::cout << getName() << " signed " << form.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cout << getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm &form) const
{
    try {
        form.execute(*this);
        std::cout << getName() << " executed " << form.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cout << getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}