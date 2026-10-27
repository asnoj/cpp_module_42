/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 03:06:56 by jcrochet          #+#    #+#             */
/*   Updated: 2026/01/17 03:08:31 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_currentIndex;
		int		_totalContacts;

		std::string	_truncate(std::string str) const;
		void		_displayRow(int index, Contact contact) const;

	public:
		PhoneBook();

		~PhoneBook();

		void	addContact();
		void	searchContact() const;
};

#endif