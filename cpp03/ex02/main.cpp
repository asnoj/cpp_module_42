/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 21:40:54 by jcrochet          #+#    #+#             */
/*   Updated: 2026/09/22 23:56:43 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	std::cout << "=== Construction ===" << std::endl;
	FragTrap a("Bob");
	FragTrap b("Alice");

	std::cout << "\n=== Attaque ===" << std::endl;
	a.attack("Alice");
	b.takeDamage(30);

	std::cout << "\n=== Reparation ===" << std::endl;
	b.beRepaired(10);

	std::cout << "\n=== HighFives ===" << std::endl;
	a.highFivesGuys();

	std::cout << "\n=== Plus d'energie ===" << std::endl;
	for (int i = 0; i < 100; i++)
		a.attack("Alice");
	a.attack("Alice");

	std::cout << "\n=== Plus de HP ===" << std::endl;
	b.takeDamage(1000);
	b.attack("Bob");
	b.beRepaired(10);
	b.highFivesGuys();

	std::cout << "\n=== Copie ===" << std::endl;
	FragTrap c(a);
	FragTrap d("tmp");
	d = b;

	std::cout << "\n=== Destruction ===" << std::endl;
	return 0;
}

