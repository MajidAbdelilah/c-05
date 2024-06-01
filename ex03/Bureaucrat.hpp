#pragma once
#include <string>
#include <iostream>

class AForm;

class Bureaucrat
{
	public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &ass);
	~Bureaucrat();
	std::string getName() const;
	int getGrade() const;
	void incGrade();
	void decGrade();
	void signForm(AForm &f);
	
	void executeForm(AForm const & form);

	class GradeTooHighException: public std::exception
	{
		public:
		GradeTooHighException();
		const char *what() const throw();
	};
	
	class GradeTooLowException: public std::exception
	{
		public:
		GradeTooLowException();
		const char * what () const throw();
	};
	


	private:
	const std::string name;
	int grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& B);
