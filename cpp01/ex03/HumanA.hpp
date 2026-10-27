/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 02:34:14 by jcrochet          #+#    #+#             */
/*   Updated: 2026/03/22 19:03:02 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class HumanA
{

private:
	std::string _name;
	Weapon& _weapon;

public:
	HumanA(std::string name, Weapon& weapon);

	void attack(void);
};

#endif