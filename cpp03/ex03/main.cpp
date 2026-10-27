/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 22:23:01 by jcrochet          #+#    #+#             */
/*   Updated: 2026/04/05 03:12:51 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "claptrap.hpp"
#include "diamondtrap.hpp"
#include "fragtrap.hpp"
#include "scavtrap.hpp"

int	main(void)
{
	std::cout << "--- Test DiamondTrap ---" << std::endl;
	DiamondTrap d("Bob");
	d.attack("target");
	d.takeDamage(50);
	d.beRepaired(20);
	d.guardGate();
	d.highFivesGuys();
	d.whoAmI();

	std::cout << "\n--- Test copie ---" << std::endl;
	DiamondTrap d2(d);
	d2.whoAmI();

	std::cout << "\n--- Fin ---" << std::endl;
	return (0);
}