/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:19:23 by jcrochet          #+#    #+#             */
/*   Updated: 2026/04/06 22:21:37 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// --- Subject test: Animal* array, half Dog half Cat ---
	std::cout << "=== Creating the array ===" << std::endl;
	const int SIZE = 6;
	Animal* zoo[SIZE];

	for (int i = 0; i < SIZE / 2; i++)
		zoo[i] = new Dog();
	for (int i = SIZE / 2; i < SIZE; i++)
		zoo[i] = new Cat();

	std::cout << std::endl;
	std::cout << "=== Sounds ===" << std::endl;
	for (int i = 0; i < SIZE; i++)
		zoo[i]->makeSound();

	std::cout << std::endl;
	std::cout << "=== Destroying the array (chained destructors) ===" << std::endl;
	for (int i = 0; i < SIZE; i++)
		delete zoo[i];

	// --- Deep copy test ---
	std::cout << std::endl;
	std::cout << "=== Deep copy test ===" << std::endl;
	Dog d1;
	d1.getBrain()->ideas[0] = "I want a bone";
	d1.getBrain()->ideas[1] = "Running in the park";

	Dog d2(d1);

	std::cout << "d1.ideas[0] = " << d1.getBrain()->ideas[0] << std::endl;
	std::cout << "d2.ideas[0] = " << d2.getBrain()->ideas[0] << std::endl;
	std::cout << "Brain addresses d1/d2 are different: "
		<< (d1.getBrain() != d2.getBrain() ? "YES (deep copy)" : "NO (shallow!)")
		<< std::endl;

	d2.getBrain()->ideas[0] = "I want a cat";
	std::cout << "After modifying d2:" << std::endl;
	std::cout << "d1.ideas[0] = " << d1.getBrain()->ideas[0] << std::endl;
	std::cout << "d2.ideas[0] = " << d2.getBrain()->ideas[0] << std::endl;

	// --- Assignment operator test ---
	std::cout << std::endl;
	std::cout << "=== operator= test ===" << std::endl;
	Cat c1;
	c1.getBrain()->ideas[0] = "Sleep 20 hours a day";
	Cat c2;
	c2 = c1;
	std::cout << "c1.ideas[0] = " << c1.getBrain()->ideas[0] << std::endl;
	std::cout << "c2.ideas[0] = " << c2.getBrain()->ideas[0] << std::endl;
	std::cout << "Brain addresses c1/c2 are different: "
		<< (c1.getBrain() != c2.getBrain() ? "YES (deep copy)" : "NO (shallow!)")
		<< std::endl;

	return 0;
}
