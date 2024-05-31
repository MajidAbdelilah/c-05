#include "Form.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &src) : name(src.name), isSigned(src.isSigned), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute) 
{
	// std::cout << "copy constructor called\n";
}

Form::~Form() {
}

Form &Form::operator=(const Form &rhs) {
    if (this != &rhs) {
        this->isSigned = rhs.isSigned;
    }
    return *this;
}

std::string Form::getName() const { return name; }
bool Form::getIsSigned() const { return isSigned; }
int Form::getGradeToSign() const { return gradeToSign; }
int Form::getGradeToExecute() const { return gradeToExecute; }

void Form::beSigned(const Bureaucrat &b) {
    if (b.getGrade() <= gradeToSign)
        isSigned = true;
    else
        throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw() { return "Grade too high"; }
const char *Form::GradeTooLowException::what() const throw() { return "Grade too low"; }

std::ostream &operator<<(std::ostream &os, const Form &f) {
    os << "Form: " << f.getName() << ", Is Signed: " << f.getIsSigned()
       << ", Grade to Sign: " << f.getGradeToSign() << ", Grade to Execute: " << f.getGradeToExecute();
    return os;
}