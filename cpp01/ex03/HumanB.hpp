/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 02:34:14 by jcrochet          #+#    #+#             */
/*   Updated: 2026/03/22 19:16:31 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class HumanB
{

private:
	std::string _name;
	Weapon *_weapon;

public:
	HumanB(std::string name);

	void setWeapon(Weapon& weapon);
	void attack(void);
};

#endif