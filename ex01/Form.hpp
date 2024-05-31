#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

class Form {
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

public:
    Form(std::string name, int gradeToSign, int gradeToExecute);
    Form(const Form &src); // Copy constructor
    ~Form(); // Destructor
    Form &operator=(const Form &rhs); // Copy assignment operator

    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(const Bureaucrat &b);

    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Form &f);