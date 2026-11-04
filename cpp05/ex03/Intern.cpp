/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:12:30 by jcrochet          #+#    #+#             */
/*   Updated: 2026/05/22 20:17:02 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void)
{
	std::cout << "[Intern] Default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout << "[Intern] Copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
	{
		std::cout << "[Intern] Assignement operator called" << std::endl;
	}

	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "[Intern] Destructor called" << std::endl;
}

static AForm *createShrubbery(std::string const &target)
{
	return new ShrubberyCreationForm(target);
}

static AForm *createRobotomy(std::string const &target)
{
	return new RobotomyRequestForm(target);
}

static AForm *createPresidential(std::string const &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string formName, const std::string targetName) const
{
	struct FormEntry
	{
		std::string name;
		AForm *(*create)(std::string const &);
	};

	FormEntry forms[] = {
		{"shrubbery creation", createShrubbery},
		{"robotomy request", createRobotomy},
		{"presidential pardon", createPresidential}};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i].name == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i].create(targetName);
		}
	}
	throw Intern::InvalidForm();
}