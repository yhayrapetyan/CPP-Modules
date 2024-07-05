/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:58:02 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/05 18:04:07 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void):
	_x(Fixed(0)),
	_y(Fixed(0))
{
	
}

Point::~Point(void)
{
	
}

Point::Point(const Point &copy): 
	_x(copy._x), _y(copy._y)
{
	
}
Point::Point(const float x, const float y):
	_x(Fixed(x)), _y(Fixed(y))
{
	
}

float	Point::getx(void) const {return _x.toFloat();}
float	Point::gety(void) const {return _y.toFloat();}

Point   &Point::operator=(const Point &fixed)
{
    if (this == &fixed)
        return *this;
    (Fixed)this->_x = fixed.getx();
    (Fixed)this->_y = fixed.gety();
    return (*this);
}