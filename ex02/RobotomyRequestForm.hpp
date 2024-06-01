#pragma once
#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& src);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
	~RobotomyRequestForm();

	void execute(Bureaucrat const & executor) const;
};