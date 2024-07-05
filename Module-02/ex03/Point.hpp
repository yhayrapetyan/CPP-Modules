/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:47:21 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/05 18:22:57 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

#include <iostream>
#include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		~Point(void);
        Point(const Point &copy);
        Point   &operator=(const Point &fixed);
		Point(const float x, const float y);

		float	getx(void) const;
		float	gety(void) const;

	private:
		Fixed const _x;
		Fixed const _y;
	
};

bool	bsp(const Point a, const Point b, const Point c, const Point point);


#endif