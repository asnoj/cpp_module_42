/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 03:17:56 by jcrochet          #+#    #+#             */
/*   Updated: 2026/01/17 03:40:19 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	PhoneBook	phoneBook;
	std::string	command;
	(void)ac;
	(void)av;

	std::cout << "Welcome to your PhoneBook!" << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
	while (true)
	{
		std::cout << "> ";
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cout << std::endl << "Exiting PhoneBook!" << std::endl;
			break ;
		}
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT")
		{
			std::cout << "Exiting PhoneBook!" << std::endl;
			break ;
		}
		else
			std::cout << "Invalid command :[" << std::endl;
	}
}