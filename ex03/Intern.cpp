#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{

}
Intern::Intern(const Intern &other)
{
	*this = other;
}
Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}
Intern::~Intern()
{

}

AForm* createShrubberyCreationForm(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomyRequestForm(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm* createPresidentialPardonForm(std::string target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	 AForm *(*arr[3])(std::string) = {createPresidentialPardonForm, createRobotomyRequestForm, createShrubberyCreationForm};
	 std::string arrNames[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	 bool isNone = (formName != arrNames[0]) && (formName != arrNames[1]) && (formName != arrNames[2]);
	 if (isNone)
		 throw Intern::FormNotFound();
	 return arr[(formName == arrNames[0]) * 0 + (formName == arrNames[1]) * 1 + (formName == arrNames[2]) * 2](target);
}

const char *Intern::FormNotFound::what() const throw()
{
	return ("Form not found");
}