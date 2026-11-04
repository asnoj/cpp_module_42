/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 02:36:18 by jcrochet          #+#    #+#             */
/*   Updated: 2026/05/22 19:47:48 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <ctime>

#define RobotomyName "RobotomyRequestForm"
#define RobotomySignGrade 72
#define RobotomyExecGrade 45

class RobotomyRequestForm : public AForm
{
private:
	std::string target;

public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	~RobotomyRequestForm(void);

	void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &form);

#endif
