/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 00:08:17 by jcrochet          #+#    #+#             */
/*   Updated: 2026/05/27 00:10:02 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void)
{
	std::srand(std::time(NULL));

	for (int i = 0; i < 9; i++)
	{
		Base *obj = generate();

		std::cout << "Via pointer  : ";
		identify(obj);

		std::cout << "Via reference: ";
		identify(*obj);

		std::cout << "---" << std::endl;
		delete obj;
	}
	return 0;
}