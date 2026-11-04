#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "=== Test signature reussie ===" << std::endl;
	Bureaucrat b1("Jean", 42);
	Form f1("Formulaire A", 50, 50);
	b1.signForm(f1);

	std::cout << "\n=== Test grade trop bas ===" << std::endl;
	Bureaucrat b2("Bob", 100);
	Form f2("Formulaire B", 50, 50);
	b2.signForm(f2);

	std::cout << "\n=== Test form grade invalide ===" << std::endl;
	try
	{
		Form f3("Formulaire C", 0, 50);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test affichage form ===" << std::endl;
	std::cout << f1 << std::endl;

	return 0;
}