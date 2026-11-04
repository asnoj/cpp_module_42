/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:31:29 by jcrochet          #+#    #+#             */
/*   Updated: 2026/09/22 20:52:10 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// AAnimal a;        // error: cannot instantiate abstract class
	// new AAnimal();    // error

	// Pointers to AAnimal are still valid
	std::cout << "=== Polymorphism via AAnimal* ===" << std::endl;
	const AAnimal* d = new Dog();
	const AAnimal* c = new Cat();

	std::cout << d->getType() << std::endl;
	std::cout << c->getType() << std::endl;
	d->makeSound();
	c->makeSound();

	delete d;
	delete c;

	// --- Array test: half Dog, half Cat ---
	std::cout << std::endl;
	std::cout << "=== Array of AAnimal* ===" << std::endl;
	const int SIZE = 6;
	AAnimal* zoo[SIZE];

	for (int i = 0; i < SIZE / 2; i++)
		zoo[i] = new Dog();
	for (int i = SIZE / 2; i < SIZE; i++)
		zoo[i] = new Cat();

	for (int i = 0; i < SIZE; i++)
		zoo[i]->makeSound();

	std::cout << std::endl;
	std::cout << "=== Destroying array ===" << std::endl;
	for (int i = 0; i < SIZE; i++)
		delete zoo[i];

	// --- Deep copy test ---
	std::cout << std::endl;
	std::cout << "=== Deep copy test ===" << std::endl;
	Dog d1;
	d1.getBrain()->ideas[0] = "I want a bone";

	Dog d2(d1);
	std::cout << "Brain addresses d1/d2 are different: "
		<< (d1.getBrain() != d2.getBrain() ? "YES (deep copy)" : "NO (shallow!)")
		<< std::endl;

	d2.getBrain()->ideas[0] = "I want a cat";
	std::cout << "d1.ideas[0] = " << d1.getBrain()->ideas[0] << std::endl;
	std::cout << "d2.ideas[0] = " << d2.getBrain()->ideas[0] << std::endl;

	return 0;
}
