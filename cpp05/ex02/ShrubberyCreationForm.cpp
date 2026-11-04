/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 19:21:55 by jcrochet          #+#    #+#             */
/*   Updated: 2026/05/22 19:50:36 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm(ShruberryName, ShruberrySignGrade, ShruberryExecGrade)
{
	std::cout << "[ShrubberyCreationForm] Default constructor called" << std::endl;
	this->target = "Default";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm(ShruberryName, ShruberrySignGrade, ShruberryExecGrade)
{
	std::cout << "[ShrubberyCreationForm] Settings constructor called" << std::endl;
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(ShruberryName, ShruberrySignGrade, ShruberryExecGrade)
{
	std::cout << "[ShrubberyCreationForm] Copy constructor called" << std::endl;
	this->target = other.target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		std::cout << "[ShrubberyCreationForm] Copy assignement operator called" << std::endl;
		this->target = other.target;
	}

	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "[ShrubberyCreationForm] Destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!getisSigned())
		throw AForm::GradeTooLowException();
	if (executor.getGrade() > getGradeExec())
		throw AForm::GradeTooLowException();
	std::ofstream file((target + "_shrubbery").c_str());
	if (!file.is_open())
		return;
	file << "        *" << std::endl;
	file << "       ***" << std::endl;
	file << "      *****" << std::endl;
	file << "     *******" << std::endl;
	file << "    *********" << std::endl;
	file << "   ***********" << std::endl;
	file << "  *************" << std::endl;
	file << " ***************" << std::endl;
	file << "*****************" << std::endl;
	file << "       |||" << std::endl;
	file << "       |||" << std::endl;
	file.close();
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &form)
{
	os << "[ShrubberyCreationForm] " << form.getName() << std::endl
	   << "[ShrubberyCreationForm] Is Signed : " << form.getisSigned() << std::endl
	   << "[ShrubberyCreationForm] Grade to sign : " << form.getGradeSign() << std::endl
	   << "[ShrubberyCreationForm] Grade to execute : " << form.getGradeExec() << std::endl;

	return (os);
}