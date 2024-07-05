/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:29:06 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/05 18:25:24 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
    Point a(0, 0), b(0, 4), c(5, 0);
    
    // Point inside the triangle
    Point point1(2, 2);
    if (bsp(a, b, c, point1))
        std::cout << "Point (2, 2) is in the triangle\n";
    else
        std::cout << "Point (2, 2) is out of the triangle\n";
    
    // Point outside the triangle
    Point point2(8, 0.91);
    if (bsp(a, b, c, point2))
        std::cout << "Point (8, 0.91) is in the triangle\n";
    else
        std::cout << "Point (8, 0.91) is out of the triangle\n";
    
    // Point at vertex A
    Point point3(0, 0);
    if (bsp(a, b, c, point3))
        std::cout << "Point (0, 0) is in the triangle\n";
    else
        std::cout << "Point (0, 0) is out of the triangle\n";
    
    // Point at vertex B
    Point point4(0, 4);
    if (bsp(a, b, c, point4))
        std::cout << "Point (0, 4) is in the triangle\n";
    else
        std::cout << "Point (0, 4) is out of the triangle\n";
    
    // Point at vertex C
    Point point5(5, 0);
    if (bsp(a, b, c, point5))
        std::cout << "Point (5, 0) is in the triangle\n";
    else
        std::cout << "Point (5, 0) is out of the triangle\n";
    
    // Point on edge AB
    Point point6(0, 2);
    if (bsp(a, b, c, point6))
        std::cout << "Point (0, 2) is in the triangle\n";
    else
        std::cout << "Point (0, 2) is out of the triangle\n";
    
    // Point on edge BC
    Point point7(2.5, 2);
    if (bsp(a, b, c, point7))
        std::cout << "Point (2.5, 2) is in the triangle\n";
    else
        std::cout << "Point (2.5, 2) is out of the triangle\n";
    
    // Point on edge CA
    Point point8(2.5, 0);
    if (bsp(a, b, c, point8))
        std::cout << "Point (2.5, 0) is in the triangle\n";
    else
        std::cout << "Point (2.5, 0) is out of the triangle\n";
    
    return 0;
}

