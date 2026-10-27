/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 20:16:01 by jcrochet          #+#    #+#             */
/*   Updated: 2026/03/22 21:20:31 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include <fstream>

int main(int ac, char **av)
{
	std::string content;
	std::string line;
	std::string filename;

	if (ac != 4)
	{
		std::cout << "3 arg plsssss >;[ " << std::endl;
		return 1;
	}

	std::ifstream inFile(av[1]);
	if (!inFile.is_open())
	{
		std::cerr << "Erreur : cant open file >;[" << std::endl;
		return 1;
	}

	while (std::getline(inFile, line))
	{
		content += line + "\n";
		while (std::getline(inFile, line))
		{
			content += line;
			if (!inFile.eof())
				content += "\n";
		}
	}
	inFile.close();
	filename = av[1] + std::string(".replace");
	std::ofstream outFile(filename.c_str());
	if (!outFile.is_open())
	{
		std::cerr << "Erreur : cant create file >;[" << std::endl;
		return 1;
	}

	std::string s1 = av[2];
	std::string s2 = av[3];
	size_t pos = 0;
	if (s1.empty())
	{
		std::cerr << "Erreur : s1 cant be empty >;[" << std::endl;
		return 1;
	}

	while ((pos = content.find(s1, pos)) != std::string::npos)
	{
		content.erase(pos, s1.size());
		content.insert(pos, s2);
		pos += s2.size();
	}
	outFile << content;
	outFile.close();
}
