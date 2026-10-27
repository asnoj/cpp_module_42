/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 22:32:02 by jcrochet          #+#    #+#             */
/*   Updated: 2026/03/31 23:31:13 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <cmath>

class Fixed
{
	private:

		int					_value;
		static const int	_fract_bits = 8;

	public:

		Fixed(void);
		Fixed(const int value);
		Fixed(const float float_value);
		~Fixed(void);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);

		int toInt( void ) const;
		float toFloat( void ) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
#endif