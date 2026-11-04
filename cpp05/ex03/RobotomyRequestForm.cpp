/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 18:36:45 by jcrochet          #+#    #+#             */
/*   Updated: 2026/05/22 19:50:33 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm(RobotomyName, RobotomySignGrade, RobotomyExecGrade)
{
	std::cout << "[RobotomyRequestForm] Default constructor called" << std::endl;
	this->target = "Default";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm(RobotomyName, RobotomySignGrade, RobotomyExecGrade)
{
	std::cout << "[RobotomyRequestForm] Settings constructor called" << std::endl;
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(RobotomyName, RobotomySignGrade, RobotomyExecGrade)
{
	std::cout << "[RobotomyRequestForm] Copy constructor called" << std::endl;
	this->target = other.target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		std::cout << "[RobotomyRequestForm] Copy assignement operator called" << std::endl;
		this->target = other.target;
	}

	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "[RobotomyRequestForm] Destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!getisSigned())
		throw AForm::GradeTooLowException();
	if (executor.getGrade() > getGradeExec())
		throw AForm::GradeTooLowException();
	std::cout << "Drilling noises....." << std::endl;
	std::time_t now = std::time(NULL);
	std::tm *localTime = std::localtime(&now);

	if (localTime->tm_sec % 2 == 0)
		std::cout << "[RobotomyRequestForm] " << this->target << " robotomy failed." << std::endl;
	else
		std::cout << "[RobotomyRequestForm] " << this->target << " has been robotomized." << std::endl;
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &form)
{
	os << "[RobotomyRequestForm] " << form.getName() << std::endl
	   << "[RobotomyRequestForm] Is Signed : " << form.getisSigned() << std::endl
	   << "[RobotomyRequestForm] Grade to sign : " << form.getGradeSign() << std::endl
	   << "[RobotomyRequestForm] Grade to execute : " << form.getGradeExec() << std::endl;

	return (os);
}