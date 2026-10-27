/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 22:22:13 by jcrochet          #+#    #+#             */
/*   Updated: 2026/03/22 22:28:05 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "1 arg plsssss >;[" << std::endl;
		return 1;
	}

	Harl harl;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int index = -1;

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == av[1])
			index = i;
	}

	switch (index)
	{
	case 0:
		harl.complain("DEBUG");
	case 1:
		harl.complain("INFO");
	case 2:
		harl.complain("WARNING");
	case 3:
		harl.complain("ERROR");
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
	return 0;
}
