/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diamondtrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 22:23:01 by jcrochet          #+#    #+#             */
/*   Updated: 2026/04/05 03:13:16 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "diamondtrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), fragtrap()
{
	std::cout << "DiamondTrap default constructed!" << std::endl;
}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),
	ScavTrap(name), fragtrap(name), _name(name)
{
	_hitPoints = 100;   // FragTrap
	_energyPoints = 50; // ScavTrap
	_attackDamage = 30; // FragTrap
	std::cout << "DiamondTrap " << _name << " constructed!" << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), fragtrap(other)
{
	*this = other;
	std::cout << "DiamondTrap " << _name << " copied!" << std::endl;
}
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		DiamondTrap::_hitPoints = other._hitPoints;
		DiamondTrap::_energyPoints = other._energyPoints;
		DiamondTrap::_attackDamage = other._attackDamage;
		DiamondTrap::_name = other._name;
	}
	std::cout << "DiamondTrap " << _name << " operator copied" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " destruction" << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}
void DiamondTrap::whoAmI(void)
{
	std::cout << "My name is " << _name << std::endl;
	std::cout << "My ClapTrap name is " << ClapTrap::_name << std::endl;
}