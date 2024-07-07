/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:13:38 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/05 16:00:05 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {
public:
	Fixed(void);
	~Fixed(void);
	Fixed(const Fixed &fixed);
	Fixed &operator=(const Fixed &fixed);
	Fixed(const int value);
	Fixed(const float value);
	void setRawBits(int const raw);
	int getRawBits(void) const;
	int toInt(void) const;
	float toFloat(void) const;

private:
	static const int _fractionalBitNB = 8;
	int _fixPointNb;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif