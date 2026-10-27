/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 02:21:36 by jcrochet          #+#    #+#             */
/*   Updated: 2026/01/20 21:58:38 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";

	std::string* stringPTR = &str;
	std::string& stringREF = str;
	
	std::cout << std::endl;
	std::cout << "Address of the string variable: " << &str << std::endl;
	std::cout << "Address held by stringPTR: " << stringPTR << std::endl
			  << "Address held by stringREF: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Value of the string variable: " << str << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl
			  << "Value pointed to by stringREF: " << stringREF << std::endl;
	return 0;
}
