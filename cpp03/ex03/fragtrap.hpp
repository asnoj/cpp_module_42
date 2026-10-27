/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fragtrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 22:23:01 by jcrochet          #+#    #+#             */
/*   Updated: 2026/04/05 03:13:03 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "claptrap.hpp"

class fragtrap : virtual public ClapTrap
{
  public:
	fragtrap();
	fragtrap(std::string name);
	fragtrap(const fragtrap &other);
	fragtrap &operator=(const fragtrap &other);
	~fragtrap();

	void attack(const std::string &target);
	void highFivesGuys(void);
};

#endif