/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 01:08:19 by jcrochet          #+#    #+#             */
/*   Updated: 2026/05/22 02:27:16 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Form(const char *name, int gradeSign, int gradeExec);
//~Form();
// Form(const Form &other);
// Form &operator=(const Form &other);
//
// std::string getName() const;
// int getGradeSign() const;
// int getGradeExec() const;
// bool getisSigned() const;
// void beSigned(Bureaucrat const &crat);

Form::Form(const char *name, int gradeSign, int gradeExec) : _Name(name), _isSigned(false), _GradeSign(gradeSign), _GradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form &other) : _Name(other._Name), _isSigned(other._isSigned), _GradeSign(other._GradeSign), _GradeExec(other._GradeExec) {}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

std::string Form::getName() const
{
	return _Name;
}

int Form::getGradeExec() const { return _GradeExec; }

int Form::getGradeSign() const { return _GradeSign; }

bool Form::getisSigned() const { return _isSigned; }

void Form::beSigned(Bureaucrat const &crat)
{
	if (crat.getGrade() <= getGradeSign())
		_isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, Form const &f)
{
	out << f.getName()
		<< ", grade sign: " << f.getGradeSign()
		<< ", grade exec: " << f.getGradeExec()
		<< ", signed: " << f.getisSigned();
	return out;
}
