#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat b1("b1", 75);
	Bureaucrat b2(b1);
	
	std::cout << "b1: " << b1;
	std::cout << "b2: " << b2;
	
	int i = 0;
	while(i < 80)
	{
		b1.incGrade();
		b2.decGrade();
		i++;
	}
	
	std::cout << b1.getName() << " " << b1.getGrade() << "\n";
	std::cout << b2.getName() << " " << b2.getGrade() << "\n";
	
	std::cout << "------------------\n";
	
	Bureaucrat b3("b3", -10);
	Bureaucrat b4("b4", 0);
	Bureaucrat b5("b5", 151);
	Bureaucrat b6("b6", 150);
	Bureaucrat b7("b7", 1);
	
	std::cout << b3 << b4 << b5 << b6 << b7;

	b5 = b4;
	std::cout << b5;

	return 0;
}