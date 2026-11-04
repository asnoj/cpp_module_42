/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 02:41:16 by jcrochet          #+#    #+#             */
/*   Updated: 2026/05/22 19:50:27 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm(PresidentialName, PresidentialSignGrade, PresidentialExecGrade)
{
	std::cout << "[PresidentialPardonForm] Default constructor called" << std::endl;
	this->target = "Default";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm(PresidentialName, PresidentialSignGrade, PresidentialExecGrade)
{
	std::cout << "[PresidentialPardonForm] Settings constructor called" << std::endl;
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(PresidentialName, PresidentialSignGrade, PresidentialExecGrade)
{
	std::cout << "[PresidentialPardonForm] Copy constructor called" << std::endl;
	this->target = other.target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		std::cout << "[PresidentialPardonForm] Copy assignement operator called" << std::endl;
		this->target = other.target;
	}

	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "[PresidentialPardonForm] Destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!getisSigned())
		throw AForm::GradeTooLowException();
	if (executor.getGrade() > getGradeExec())
		throw AForm::GradeTooLowException();
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &form)
{
	os << "[PresidentialPardonForm] " << form.getName() << std::endl
	   << "[PresidentialPardonForm] Is Signed : " << form.getisSigned() << std::endl
	   << "[PresidentialPardonForm] Grade to sign : " << form.getGradeSign() << std::endl
	   << "[PresidentialPardonForm] Grade to execute : " << form.getGradeExec() << std::endl;

	return (os);
}