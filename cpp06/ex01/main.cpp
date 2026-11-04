/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 18:47:25 by jcrochet          #+#    #+#             */
/*   Updated: 2026/05/26 23:22:18 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	Data d;
	uintptr_t raw;
	Data *ptr;

	d.x = 42;
	raw = Serializer::serialize(&d);
	ptr = Serializer::deserialize(raw);
	std::cout << "original  : " << &d << "\n";
	std::cout << "serialized: " << raw << "\n";
	std::cout << "deserialized: " << ptr << "\n";
	std::cout << (ptr == &d ? "OK" : "KO") << "\n";
	return 0;
}