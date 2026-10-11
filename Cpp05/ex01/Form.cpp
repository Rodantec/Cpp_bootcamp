#include "Form.hpp"

Form::Form() : _name("default form"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}
Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{

}
Form &Form::operator=(const Form &copy)
{
    _signed = copy._signed;
    return *this;
}
Form::~Form()
{

}
std::string Form::getName() const
{
    return _name;
}
bool Form::getSigned() const
{
    return _signed;
}
int Form::getGradeToSign() const
{
    return _gradeToSign;
}
int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() >= _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form: grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form: grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const Form &copy)
{
    std::cout << "Form " << copy.getName() << ", signed: " << (copy.getSigned() ? "yes" : "no") << ", grade to sign: " << copy.getGradeToSign() << ", grade to execute: " << copy.getGradeToExecute();
    return out;
}