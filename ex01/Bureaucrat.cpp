#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): name(name)
{
	try
	{
		if(grade > 150)
			throw Bureaucrat::GradeTooLowException();
		if(grade < 1)
			throw Bureaucrat::GradeTooHighException();
		
		this->grade = grade;
	}
	catch (Bureaucrat::GradeTooLowException e)
	{
		std::cout << e.what();
		this->grade = 150;
	}catch (Bureaucrat::GradeTooHighException e)
	{
		std::cout << e.what();
		this->grade = 1;
	}
}
Bureaucrat::Bureaucrat(const Bureaucrat &copy): name(copy.name)
{
	*this = copy;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &ass)
{
	this->grade = ass.grade;
	return *this;
}
Bureaucrat::~Bureaucrat()
{
	return ;
}
std::string Bureaucrat::getName() const
{
	return this->name;
}
int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::incGrade()
{
	try
	{
		if((grade - 1) < 1)
			throw Bureaucrat::GradeTooHighException();
		
		grade--;
	}
	catch (Bureaucrat::GradeTooHighException e)
	{
		std::cout << e.what();
	}
}
void Bureaucrat::decGrade()
{
	try
	{
		if((grade + 1) > 150)
			throw Bureaucrat::GradeTooLowException();
		
		grade++;
	}
	catch (Bureaucrat::GradeTooLowException e)
	{
		std::cout << e.what();
	}
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
{
	return ;
}

const char * Bureaucrat::GradeTooHighException::what () const throw()
{
	return "exception: GradeTooHighException catched\n";
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
	return ;
}
const char * Bureaucrat::GradeTooLowException::what () const throw()
{
	return "exception: GradeTooLowException catched\n";
}

	

std::ostream& operator<<(std::ostream& os, const Bureaucrat& B)
{
    os << B.getName() << ", bureaucrat grade " << B.getGrade() << "\n";
    return os;
}

void Bureaucrat::signForm(Form &f) {
    try {
        f.beSigned(*this);
        std::cout << this->getName() << " signed " << f.getName() << std::endl;
    } catch (Form::GradeTooLowException &e) {
        std::cout << this->getName() << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
		throw e;
	}
}