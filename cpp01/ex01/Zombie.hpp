/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 23:53:23 by jcrochet          #+#    #+#             */
/*   Updated: 2026/03/22 19:06:32 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{

private:
	std::string _name;

public:
	Zombie(std::string name);

	Zombie(void);

	~Zombie(void);

	void setname(std::string name);

	void announce(void);
};

#endif