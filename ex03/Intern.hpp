#pragma once
#include "AForm.hpp"

class Intern
{
	public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();

	AForm *makeForm(std::string formName, std::string target);
	class FormNotFound : public std::exception
	{
		virtual const char *what() const throw();
	};
};
	