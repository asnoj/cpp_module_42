/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 00:35:35 by jcrochet          #+#    #+#             */
/*   Updated: 2026/05/22 20:20:10 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
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

	virtual void execute(Bureaucrat const & executor) const = 0;
	AForm(const char *name, int gradeSign, int gradeExec);
	virtual ~AForm();
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);

	std::string getName() const;
	int getGradeSign() const;
	int getGradeExec() const;
	bool getisSigned() const;
	void beSigned(Bureaucrat const &crat);
};

std::ostream &operator<<(std::ostream &out, AForm const &f);

#endif