// main.cpp
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;

	// Test valides
	std::cout << "\n=== Test shrubbery creation ===" << std::endl;
	AForm *f1 = someRandomIntern.makeForm("shrubbery creation", "home");
	std::cout << *f1 << std::endl;
	delete f1;

	std::cout << "\n=== Test robotomy request ===" << std::endl;
	AForm *f2 = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *f2 << std::endl;
	delete f2;

	std::cout << "\n=== Test presidential pardon ===" << std::endl;
	AForm *f3 = someRandomIntern.makeForm("presidential pardon", "Marvin");
	std::cout << *f3 << std::endl;
	delete f3;

	// Test form inexistant
	std::cout << "\n=== Test form inexistant ===" << std::endl;
	try
	{
		AForm *f4 = someRandomIntern.makeForm("invalid form", "target");
		delete f4;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}