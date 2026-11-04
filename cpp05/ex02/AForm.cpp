/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 01:08:19 by jcrochet          #+#    #+#             */
/*   Updated: 2026/05/22 18:36:21 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const char *name, int gradeSign, int gradeExec) : _Name(name), _isSigned(false), _GradeSign(gradeSign), _GradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm &other) : _Name(other._Name), _isSigned(other._isSigned), _GradeSign(other._GradeSign), _GradeExec(other._GradeExec) {}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

std::string AForm::getName() const
{
	return _Name;
}

int AForm::getGradeExec() const { return _GradeExec; }

int AForm::getGradeSign() const { return _GradeSign; }

bool AForm::getisSigned() const { return _isSigned; }

void AForm::beSigned(Bureaucrat const &crat)
{
	if (crat.getGrade() <= getGradeSign())
		_isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, AForm const &f)
{
	out << f.getName()
		<< ", grade sign: " << f.getGradeSign()
		<< ", grade exec: " << f.getGradeExec()
		<< ", signed: " << f.getisSigned();
	return out;
}
