/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 02:36:18 by jcrochet          #+#    #+#             */
/*   Updated: 2026/05/22 19:47:50 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <fstream>

#define PresidentialName "PresidentialPardonForm"
#define PresidentialSignGrade 25
#define PresidentialExecGrade 5

class PresidentialPardonForm : public AForm
{
private:
	std::string target;

public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	~PresidentialPardonForm(void);

	void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &form);

#endif
