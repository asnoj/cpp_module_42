/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fragtrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 22:23:01 by jcrochet          #+#    #+#             */
/*   Updated: 2026/04/05 03:13:08 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fragtrap.hpp"

fragtrap::fragtrap() : ClapTrap()
{
	std::cout << "Fragtrap " << _name << " init" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}
fragtrap::fragtrap(std::string name) : ClapTrap(name)
{
	std::cout << "Fragtrap " << _name << " constructor" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}
fragtrap::fragtrap(const fragtrap &other) : ClapTrap(other)
{
	*this = other;
	std::cout << "Fragtrap " << _name << " copied !" << std::endl;
}
fragtrap &fragtrap::operator=(const fragtrap &other)
{
	if (this != &other)
	{
		fragtrap::_hitPoints = other._hitPoints;
		fragtrap::_energyPoints = other._energyPoints;
		fragtrap::_attackDamage = other._attackDamage;
		fragtrap::_name = other._name;
	}
	std::cout << "Fragtrap " << _name << " operator copied" << std::endl;
	return (*this);
}
fragtrap::~fragtrap()
{
	std::cout << "Fragtrap " << _name << " destruction" << std::endl;
}

void	fragtrap::attack(const std::string &target)
{
	if (_hitPoints == 0 || _energyPoints == 0)
	{
		std::cout << "Fragtrap " << _name << " can't attack, no energy or health!" << std::endl;
		return ;
	}
	_energyPoints -= 1;
	std::cout << "Fragtrap " << _name << " attacks " << target << ",causing " << _attackDamage << " points of damage!" << std::endl;
}

void	fragtrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " requests a high five!" << std::endl;
}