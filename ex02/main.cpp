#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>


int main()
{
	Bureaucrat b1("b1", 1);
	Bureaucrat b2("b2", 150);
	RobotomyRequestForm r1("r1");
	PresidentialPardonForm p1("p1");
	ShrubberyCreationForm s1("s1");

	b1.signForm(r1);
	b1.executeForm(r1);

	r1.beSigned(b1);
	r1.execute(b1);
	r1.execute(b1);
	r1.execute(b1);
	r1.execute(b1);
	r1.execute(b1);

	p1.beSigned(b1);
	p1.execute(b1);

	s1.beSigned(b1);
	s1.execute(b1);


	b2.signForm(r1);
	b2.executeForm(r1);

	b2.signForm(p1);
	b2.executeForm(p1);

	b2.signForm(s1);
	b2.executeForm(s1);
	return 0;
}