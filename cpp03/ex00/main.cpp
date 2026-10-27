/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 21:10:35 by jcrochet          #+#    #+#             */
/*   Updated: 2026/04/04 21:10:35 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	std::cout << "=== Construction ===" << std::endl;
	ClapTrap a("Bob");
	ClapTrap b("Alice");

	std::cout << "\n=== Attaque ===" << std::endl;
	a.attack("Alice");
	b.takeDamage(0);

	std::cout << "\n=== Réparation ===" << std::endl;
	a.takeDamage(5);
	a.beRepaired(3);

	std::cout << "\n=== Plus d'énergie ===" << std::endl;
	for (int i = 0; i < 10; i++)
		a.attack("Alice");
	a.attack("Alice");

	std::cout << "\n=== Plus de HP ===" << std::endl;
	b.takeDamage(100);
	b.beRepaired(5);
	b.attack("Bob");

	std::cout << "\n=== Copie ===" << std::endl;
	ClapTrap c(a);
	ClapTrap d("tmp");
	d = b;

	std::cout << "\n=== Destruction ===" << std::endl;
	return 0;
}
