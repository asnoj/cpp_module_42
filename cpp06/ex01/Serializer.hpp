/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 17:51:04 by jcrochet          #+#    #+#             */
/*   Updated: 2026/05/26 23:24:34 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <sstream>
#include <cmath>
#include <cstring>
#include <climits>
#include <cfloat>
#include <iomanip>
#include <stdint.h>

struct Data {
	int x;
};

class Serializer
{
private:
	Serializer(void);
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &other);
	~Serializer(void);

public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};
#endif