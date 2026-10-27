/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scavtrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 22:23:01 by jcrochet          #+#    #+#             */
/*   Updated: 2026/04/05 03:12:57 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scavtrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " constructed!" << std::endl;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " constructed!" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &other)
{
	*this = other;
	std::cout << "ScavTrap " << _name << " copied !" << std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		ScavTrap::_hitPoints = other._hitPoints;
		ScavTrap::_energyPoints = other._energyPoints;
		ScavTrap::_attackDamage = other._attackDamage;
		ScavTrap::_name = other._name;
	}
	std::cout << "ScavTrap " << _name << " operator copied" << std::endl;
	return (*this);
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destruction" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (_hitPoints == 0 || _energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " can't attack, no energy or health!" << std::endl;
		return ;
	}
	_energyPoints -= 1;
	std::cout << "ScavTrap " << _name << " attacks " << target << ",causing " << _attackDamage << " points of damage!" << std::endl;
}
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}