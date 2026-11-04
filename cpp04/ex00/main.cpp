/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 21:57:00 by jcrochet          #+#    #+#             */
/*   Updated: 2026/04/06 22:03:26 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "--- Subject test ---" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j    = new Dog();
	const Animal* i    = new Cat();

	std::cout << j->getType() << std::endl;  // Dog
	std::cout << i->getType() << std::endl;  // Cat
	i->makeSound();    // Cat: Meow!   (virtual)
	j->makeSound();    // Dog: Woof!   (virtual)
	meta->makeSound(); // Animal: ...

	delete meta;
	delete j;
	delete i;

	std::cout << std::endl;
	std::cout << "--- Test copy ---" << std::endl;
	Dog d1;
	Dog d2(d1);
	Dog d3;
	d3 = d1;
	d1.makeSound();
	d2.makeSound();
	d3.makeSound();

	std::cout << std::endl;
	std::cout << "--- Test WrongAnimal (without virtual) ---" << std::endl;
	const WrongAnimal* wa = new WrongAnimal();
	const WrongAnimal* wc = new WrongCat();

	wc->makeSound();
	wa->makeSound();

	delete wa;
	delete wc;

	std::cout << std::endl;
	std::cout << "--- Direct comparison ---" << std::endl;
	std::cout << "from Animal* -> Cat:      ";
	const Animal* poly = new Cat();
	poly->makeSound();  // Meow  (virtual => OK)
	delete poly;

	std::cout << "from WrongAnimal* -> WrongCat: ";
	const WrongAnimal* wrong = new WrongCat();
	wrong->makeSound(); // WrongAnimal
	delete wrong;

	return 0;
}
