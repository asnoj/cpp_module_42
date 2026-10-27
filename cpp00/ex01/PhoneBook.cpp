/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 02:50:19 by jcrochet          #+#    #+#             */
/*   Updated: 2026/05/11 21:47:37 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

// Constructeur
PhoneBook::PhoneBook() : _currentIndex(0), _totalContacts(0)
{
}

// Destructeur
PhoneBook::~PhoneBook()
{
}

void	PhoneBook::addContact()
{
	std::string	input;

	Contact& contact = this->_contacts[this->_currentIndex];

	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	contact.setFirstName(input);

	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	contact.setLastName(input);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	contact.setNickname(input);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	contact.setPhoneNumber(input);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	contact.setDarkestSecret(input);

	this->_currentIndex = (this->_currentIndex + 1) % 8;
	if (this->_totalContacts < 8)
		this->_totalContacts++;
}

void	PhoneBook::searchContact() const
{
	int	i;
	i = -1;

	if (this->_totalContacts == 0)
	{
		std::cout << "PhoneBook is empty. Please add contacts :>" << std::endl;
		return ;
	}

	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "| Index | First Name | Last Name | Nickname |" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;

	while (++i < this->_totalContacts)
	{
		this->_displayRow(i, this->_contacts[i]);
	}

	std::cout << "-------------------------------------------" << std::endl;
}

void	PhoneBook::_displayRow(int index, Contact contact) const
{
	std::cout << "| " << index << "     | "
			<< this->_truncate(contact.getFirstName()) << " | "
			<< this->_truncate(contact.getLastName()) << " | "
			<< this->_truncate(contact.getNickname()) << " |"
			<< std::endl;
}

std::string	PhoneBook::_truncate(std::string str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	if (str.length() < 10)
		str.insert(0, 10 - str.length(), ' ');
	return str;
}