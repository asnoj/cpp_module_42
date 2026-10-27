/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 02:00:09 by jcrochet          #+#    #+#             */
/*   Updated: 2026/01/18 02:19:48 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main(void)
{
	int hordeSize = 5;

	std::cout << "=== Creating a horde ===" << std::endl;
	Zombie *horde = zombieHorde(hordeSize, "herissonzombie");

	std::cout << "\n=== Announcing ===" << std::endl;
	for (int i = 0; i < hordeSize; i++)
		horde[i].announce();

	std::cout << "\n=== Destroying ===" << std::endl;
	delete[] horde;

	return 0;
}