/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 17:51:22 by jcrochet          #+#    #+#             */
/*   Updated: 2026/05/26 23:14:45 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <limits>

Serializer::Serializer(void)
{
	std::cout << "[Serializer] Default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &other)
{
	(void)other;
	std::cout << "[Serializer] Copy constructor called" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	if (this != &other)
	{
		std::cout << "[Serializer] Assignement operator called" << std::endl;
	}

	return (*this);
}

Serializer::~Serializer(void)
{
	std::cout << "[Serializer] Destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}