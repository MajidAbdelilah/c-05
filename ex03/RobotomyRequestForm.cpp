#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	// Implement the logic for making drilling noises and informing about the robotomy.
	if(executor.getGrade() > getGradeToExecute()) {
		throw GradeTooLowException();
	}
	std::cout << "* drilling noises *" << std::endl;
	std::srand(std::time(0));
	if (std::rand() % 2 == 0) {
		std::cout << getTarget() << " has been robotomized successfully." << std::endl;
	} else {
		std::cout << "Robotomization of " << getTarget() << " has failed." << std::endl;
	}
}