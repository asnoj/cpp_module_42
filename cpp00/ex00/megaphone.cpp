/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 00:54:18 by jcrochet          #+#    #+#             */
/*   Updated: 2026/05/11 21:47:13 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

size_t ft_strlen(char *s)
{
	size_t i;
	i = -1;
	while (s[++i])
		;
	return (i);
}

int	main(int ac, char ** av)
{
	size_t		i;
	size_t		j;

	i = -1;
	j = 0;
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (++j < (size_t)ac)
	{
		while (++i < ft_strlen(av[j]))
			av[j][i] = std::toupper(av[j][i]);
		std::cout << av[j];
		i = -1;
	}
	std::cout << std::endl;
	return (0);
}