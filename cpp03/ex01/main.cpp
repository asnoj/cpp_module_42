/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 21:40:54 by jcrochet          #+#    #+#             */
/*   Updated: 2026/04/04 21:46:55 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	std::cout << "=== Construction ===" << std::endl;
	ScavTrap a("Bob");
	ScavTrap b("Alice");

	std::cout << "\n=== Attaque ===" << std::endl;
	a.attack("Alice");
	b.takeDamage(20);

	std::cout << "\n=== Réparation ===" << std::endl;
	b.beRepaired(10);

	std::cout << "\n=== GuardGate ===" << std::endl;
	a.guardGate();

	std::cout << "\n=== Plus d'énergie ===" << std::endl;
	for (int i = 0; i < 50; i++)
		a.attack("Alice");
	a.attack("Alice");

	std::cout << "\n=== Plus de HP ===" << std::endl;
	b.takeDamage(1000);
	b.attack("Bob");
	b.beRepaired(10);
	b.guardGate();

	std::cout << "\n=== Copie ===" << std::endl;
	ScavTrap c(a);
	ScavTrap d("tmp");
	d = b;

	std::cout << "\n=== Destruction ===" << std::endl;
	return 0;
}
