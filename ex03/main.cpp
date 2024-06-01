#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	Bureaucrat b("b", 1);
	AForm *rrf;
	AForm *ppf;
	AForm *scf;
	try
	{
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
		scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		b.signForm(*rrf);
		b.executeForm(*rrf);
		b.signForm(*ppf);
		b.executeForm(*ppf);
		b.signForm(*scf);
		b.executeForm(*scf);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete rrf;
	delete ppf;
	delete scf;

	try {
		AForm *form = someRandomIntern.makeForm("nonexistent form", "Bender");
		std::cout << *form << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}