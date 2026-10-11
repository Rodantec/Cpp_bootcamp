#include "AForm.hpp"

AForm::AForm() : _name("default AForm"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Bureaucrat::GradeTooLowException();
}
AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{

}
AForm::~AForm()
{

}
std::string AForm::getName() const
{
    return _name;
}
bool AForm::getSigned() const
{
    return _signed;
}
int AForm::getGradeToSign() const
{
    return _gradeToSign;
}
int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > _gradeToSign)
        throw Bureaucrat::GradeTooLowException();
    _signed = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}
const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}
AForm &AForm::operator=(const AForm &copy)
{
    _signed = copy._signed;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const AForm &copy)
{
    out << "Form " << copy.getName() << ", signed: " << (copy.getSigned() ? "yes" : "no") << ", grade to sign: " << copy.getGradeToSign() << ", grade to execute: " << copy.getGradeToExecute();
    return out;
}
void AForm::execute(const Bureaucrat &executor) const
{
    if (!_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw Bureaucrat::GradeTooLowException();
}