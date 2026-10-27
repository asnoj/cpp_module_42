/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 19:09:05 by jcrochet          #+#    #+#             */
/*   Updated: 2026/03/22 19:14:19 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _name(type)
{
}

const std::string& Weapon::getType(void)
{
	return this->_name;
}

void Weapon::setType(std::string type)
{
	this->_name = type;
}
