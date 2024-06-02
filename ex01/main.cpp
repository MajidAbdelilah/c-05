#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    Bureaucrat b1("John", 0);
    Bureaucrat b2("John", 151);
 
    // Test Form constructor
    try {
        Form f1("Form1", 0, 1);
    } catch (const std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    try {
        Form f2("Form1", 151, 1);
    } catch (const std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Test Form::beSigned
    try {
        Bureaucrat b3("John", 50);
        Form f3("Form1", 50, 1);
        f3.beSigned(b3);
        std::cout << "Form signed successfully" << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
	// Test Form::beSigned
    try {
        Bureaucrat b3("John", 50);
        Form f3("Form1", 40, 1);
        f3.beSigned(b3);
        std::cout << "Form signed successfully" << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
	std::cout << "--------------------------------------" << std::endl;
    // Test Bureaucrat::signForm
    try {
        Bureaucrat b4("dark", 50);
        Form f4("Form4", 50, 1);
        b4.signForm(f4);
        std::cout << f4 << std::endl;
	} catch (const std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    // Test Bureaucrat::signForm
    try {
        Bureaucrat b4("dark2", 150);
        Form f4("Form4", 50, 1);
        b4.signForm(f4);
        std::cout << f4 << std::endl;
	} catch (const std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Test Form copy constructor
    try {
        Form f6("Form6", 50, 1);
        Form f7(f6);
		std::cout << f7 << std::endl; // Print f7
    } catch (const std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

 // Test Form copy assignment operator
	try {
		Form f8("Form8", 50, 1);
		Form f9 = f8;
		std::cout << f9 << std::endl; // Print f9
	} catch (const std::exception &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

    return 0;
}