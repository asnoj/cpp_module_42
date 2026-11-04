/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 22:19:34 by jcrochet          #+#    #+#             */
/*   Updated: 2026/05/21 23:40:37 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "=== Test creation valide ===" << std::endl;
	Bureaucrat b("Jean", 42);
	std::cout << b << std::endl;

	std::cout << "=== Test grade trop haut ===" << std::endl;
	try
	{
		Bureaucrat b2("Bob", 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "=== Test grade trop bas ===" << std::endl;
	try
	{
		Bureaucrat b3("Alice", 151);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "=== Test bureau_plus sur grade 1 ===" << std::endl;
	try
	{
		Bureaucrat b4("Max", 1);
		b4.bureau_plus();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "=== Test bureau_minus sur grade 150 ===" << std::endl;
	try
	{
		Bureaucrat b5("Tom", 150);
		b5.bureau_minus();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "=== Test increment/decrement normal ===" << std::endl;
	Bureaucrat b6("Paul", 50);
	std::cout << b6 << std::endl;
	b6.bureau_plus();
	std::cout << b6 << std::endl;
	b6.bureau_minus();
	std::cout << b6 << std::endl;

	return 0;
}
