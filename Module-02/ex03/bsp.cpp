/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:04:36 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/05 18:22:48 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static int	set(const Point p1, const Point p2, const Point p3)
{
	int	p;

	p = ((p1.getx() - p3.getx()) * (p2.gety() - p3.gety()) - 
		(p2.getx() - p3.getx()) * (p1.gety() - p3.gety()));
	return (p);
}

bool	bsp(const Point a, const Point b, const Point c, const Point point)
{
	int		s1, s2, s3;
	bool	minus, plus;

	s1 = set(point, a, b);
	s2 = set(point, b, c);
	s3 = set(point, c, a);

	minus = (s1 <= 0) || (s2 <= 0) || (s3 <= 0);
	plus = (s1 >= 0) || (s2 >= 0) || (s3 >= 0);

	return (!(minus && plus));
}
