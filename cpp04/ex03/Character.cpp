/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 23:56:24 by jcrochet          #+#    #+#             */
/*   Updated: 2026/04/08 00:32:01 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const& name) : name(name), floorSize(0)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = 0;
	for (int i = 0; i < 100; i++)
		this->floor[i] = 0;
	std::cout << "Character [" << name << "] constructor called" << std::endl;
}

Character::Character(const Character& other) : ICharacter(), name(other.name), floorSize(0)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = 0;
	for (int i = 0; i < 100; i++)
		this->floor[i] = 0;
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone();
	}
	std::cout << "Character copy constructor called" << std::endl;
}

Character& Character::operator=(const Character& other)
{
	std::cout << "Character assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		for (int i = 0; i < 4; i++)
		{
			delete this->inventory[i];
			this->inventory[i] = 0;
		}
		for (int i = 0; i < 4; i++)
		{
			if (other.inventory[i])
				this->inventory[i] = other.inventory[i]->clone();
		}
	}
	return *this;
}

Character::~Character()
{
	std::cout << "Character [" << name << "] destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->inventory[i];
	for (int i = 0; i < floorSize; i++)
		delete this->floor[i];
}

std::string const& Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || !this->inventory[idx])
		return;
	if (this->floorSize < 100)
		this->floor[this->floorSize++] = this->inventory[idx];
	this->inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || !this->inventory[idx])
		return;
	this->inventory[idx]->use(target);
}