// main.cpp
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	// Test ShrubberyCreationForm
	std::cout << "=== Test Shrubbery ===" << std::endl;
	Bureaucrat b1("Jean", 137);
	ShrubberyCreationForm s1("home");
	b1.signForm(s1);
	b1.executeForm(s1);

	// Test RobotomyRequestForm
	std::cout << "\n=== Test Robotomy ===" << std::endl;
	Bureaucrat b2("Bob", 45);
	RobotomyRequestForm r1("Bender");
	b2.signForm(r1);
	b2.executeForm(r1);

	// Test PresidentialPardonForm
	std::cout << "\n=== Test Presidential ===" << std::endl;
	Bureaucrat b3("Alice", 5);
	PresidentialPardonForm p1("Marvin");
	b3.signForm(p1);
	b3.executeForm(p1);

	// Test grade trop bas pour executer
	std::cout << "\n=== Test grade insuffisant ===" << std::endl;
	Bureaucrat b4("Low", 149);
	ShrubberyCreationForm s2("garden");
	b4.signForm(s2);
	b4.executeForm(s2);

	return 0;
}