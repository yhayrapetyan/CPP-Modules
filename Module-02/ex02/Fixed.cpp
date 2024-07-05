/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:13:21 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/05 17:03:00 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	// std::cout << "Default constructor called\n";
	this->_fixPointNb = 0;
}
Fixed::Fixed(const int value)
{
	// std::cout << "Int constructor called\n";
	this->_fixPointNb = value << this->_fractionalBitNB;
}

Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called\n";
	this->_fixPointNb = roundf(value * (1 << _fractionalBitNB));
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &fixed)
{
	// std::cout << "Copy constructor called\n";
	*this = fixed;
}

Fixed   &Fixed::operator=(const Fixed &fixed)
{
	// std::cout << "Copy assignment operator\n";
    this->_fixPointNb = fixed.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called\n";
	return (this->_fixPointNb);
}

void    Fixed::setRawBits(int const raw)
{
	// std::cout << "Copy assignment operator called \n";
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

bool    Fixed::operator>(const Fixed &fixed)  const {return (this->getRawBits() > fixed.getRawBits());}
bool    Fixed::operator<(const Fixed &fixed)  const {return (this->getRawBits() < fixed.getRawBits());}
bool    Fixed::operator>=(const Fixed &fixed) const {return (this->getRawBits() >= fixed.getRawBits());}
bool    Fixed::operator<=(const Fixed &fixed) const {return (this->getRawBits() <= fixed.getRawBits());}
bool    Fixed::operator==(const Fixed &fixed) const {return (this->getRawBits() == fixed.getRawBits());}
bool    Fixed::operator!=(const Fixed &fixed) const {return (this->getRawBits() != fixed.getRawBits());}

Fixed   Fixed::operator+(const Fixed &fixed) const  {return (Fixed(this->toFloat() + fixed.toFloat()));}
Fixed   Fixed::operator-(const Fixed &fixed) const  {return (Fixed(this->toFloat() - fixed.toFloat()));}
Fixed   Fixed::operator*(const Fixed &fixed) const  {return (Fixed(this->toFloat() * fixed.toFloat()));}
Fixed   Fixed::operator/(const Fixed &fixed) const  {return (Fixed(this->toFloat() / fixed.toFloat()));}


Fixed   Fixed::operator++(int)
{
    Fixed   tmp;

	tmp = *this;
    ++this->_fixPointNb;
    return (tmp);
}

Fixed   Fixed::operator--(int)
{
    Fixed   tmp;
	
	tmp = *this;
    --this->_fixPointNb;
    return (tmp);
}

Fixed   &Fixed::operator++(void)
{
    ++this->_fixPointNb;
	// this->setRawBits(this->getRawBits() + 1);
    return (*this);
}

Fixed   &Fixed::operator--(void)
{
    ++this->_fixPointNb;
    return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

Fixed   &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed   &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

const   Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
    if (a < b)
        return (a);
    return (b);
}

const   Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
    if (a > b)
        return (a);
    return (b);
}
