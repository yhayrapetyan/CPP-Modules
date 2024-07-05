/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:13:21 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/05 16:23:39 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called\n";
	this->_fixPointNb = 0;
}
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called\n";
	this->_fixPointNb = value << this->_fractionalBitNB;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called\n";
	this->_fixPointNb = roundf(value * (1 << _fractionalBitNB));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called\n";
	*this = fixed;
}

Fixed   &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator\n";
    this->_fixPointNb = fixed.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->_fixPointNb);
}

void    Fixed::setRawBits(int const raw)
{
	std::cout << "Copy assignment operator called \n";
	this->_fixPointNb = raw;
}

int     Fixed::toInt(void) const
{
	return (this->_fixPointNb >> _fractionalBitNB);
}

float   Fixed::toFloat(void) const          
{
	return (this->_fixPointNb / float(1 << _fractionalBitNB));
}
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

