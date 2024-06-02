#pragma once
#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

class AForm {
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

public:
    AForm(std::string name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &src); // Copy constructor
    AForm &operator=(const AForm &rhs); // Copy assignment operator
    virtual ~AForm(); // Destructor

    std::string getName() const;
	bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(const Bureaucrat &b);


    // Add this pure virtual function
    virtual void execute(Bureaucrat const & executor) const = 0;

    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const AForm &f);