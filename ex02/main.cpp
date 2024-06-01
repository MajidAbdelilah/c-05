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

	try {
		b1.signForm(r1);
		b1.executeForm(r1);
	}	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try{
		r1.beSigned(b1);
		r1.execute(b1);
		r1.execute(b1);
		r1.execute(b1);
		r1.execute(b1);
		r1.execute(b1);
	}	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	try{
		p1.beSigned(b1);
		p1.execute(b1);
	}	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	try{
		s1.beSigned(b1);
		s1.execute(b1);
	}	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	try{
		b2.signForm(r1);
		b2.executeForm(r1);
	}	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	try{
		b2.signForm(p1);
		b2.executeForm(p1);
	}	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	try{
		b2.signForm(s1);
		b2.executeForm(s1);
	}	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}