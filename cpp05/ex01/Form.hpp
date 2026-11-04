/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 00:35:35 by jcrochet          #+#    #+#             */
/*   Updated: 2026/05/22 02:25:03 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{

private:
	std::string const _Name;
	bool _isSigned;
	const int _GradeSign;
	const int _GradeExec;

public:
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "Grade too high !";
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "Grade too Low !";
		}
	};




	Form(const char *name, int gradeSign, int gradeExec);
	~Form();
	Form(const Form &other);
	Form &operator=(const Form &other);

	std::string getName() const;
	int getGradeSign() const;
	int getGradeExec() const;
	bool getisSigned() const;
	void beSigned(Bureaucrat const &crat);
};

std::ostream &operator<<(std::ostream &out, Form const &f);

#endif