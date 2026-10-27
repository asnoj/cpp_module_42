/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   claptrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 22:23:01 by jcrochet          #+#    #+#             */
/*   Updated: 2026/04/05 03:13:21 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "claptrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap " << _name << " init" << std::endl;
	_hitPoints = 0;
	_energyPoints = 0;
	_attackDamage = 0;
	_name = "";
}
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10),
	_energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " constructed!" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "ClapTrap " << _name << " copied !" << std::endl;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		ClapTrap::_attackDamage = other._attackDamage;
		ClapTrap::_energyPoints = other._energyPoints;
		ClapTrap::_hitPoints = other._hitPoints;
		ClapTrap::_name = other._name;
	}
	std::cout << "ClapTrap " << _name << " operator copied" << std::endl;
	return (*this);
}
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destructor!" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (_hitPoints == 0 || _energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack, no energy or health!" << std::endl;
		return ;
	}
	_energyPoints -= 1;
	std::cout << "ClapTrap " << _name << " attacks " << target << ",causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
		return ;
	}
	if (amount >= _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! HP left: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0 || _energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " can't repair, no energy or health!" << std::endl;
		return ;
	}
	_energyPoints -= 1;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " HP! HP now: " << _hitPoints << std::endl;
}