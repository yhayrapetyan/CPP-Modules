/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:29:06 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/05 17:22:29 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	// Fixed a;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;

	Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    Fixed const c(10);
    Fixed const d(-10);
    Fixed const e(2.5f);
    Fixed const f(2.5f);
    
    std::cout << "Initial values:" << std::endl;
    std::cout << "a: " << a << " (expected: 0)" << std::endl;
    std::cout << "b: " << b << " (expected: 10.10)" << std::endl;
    std::cout << "c: " << c << " (expected: 10)" << std::endl;
    std::cout << "d: " << d << " (expected: -10)" << std::endl;
    std::cout << "e: " << e << " (expected: 2.50)" << std::endl;
    std::cout << "f: " << f << " (expected: 2.50)" << std::endl;

    std::cout << "\nTesting increment/decrement:" << std::endl;
    std::cout << "a: " << a << " (expected: 0)" << std::endl;
    std::cout << "++a: " << ++a << " (expected: 1)" << std::endl;
    std::cout << "a: " << a << " (expected: 1)" << std::endl;
    std::cout << "a++: " << a++ << " (expected: 1)" << std::endl;
    std::cout << "a: " << a << " (expected: 2)" << std::endl;
    std::cout << "--a: " << --a << " (expected: 1)" << std::endl;
    std::cout << "a: " << a << " (expected: 1)" << std::endl;
    std::cout << "a--: " << a-- << " (expected: 1)" << std::endl;
    std::cout << "a: " << a << " (expected: 0)" << std::endl;

    std::cout << "\nTesting arithmetic operators:" << std::endl;
    std::cout << "c + e: " << (c + e) << " (expected: 12.50)" << std::endl;
    std::cout << "c - e: " << (c - e) << " (expected: 7.50)" << std::endl;
    std::cout << "c * e: " << (c * e) << " (expected: 25.00)" << std::endl;
    std::cout << "c / e: " << (c / e) << " (expected: 4.00)" << std::endl;

    std::cout << "\nTesting comparison operators:" << std::endl;
    std::cout << "c > d: " << (c > d) << " (expected: 1)" << std::endl;
    std::cout << "c < d: " << (c < d) << " (expected: 0)" << std::endl;
    std::cout << "c >= d: " << (c >= d) << " (expected: 1)" << std::endl;
    std::cout << "c <= d: " << (c <= d) << " (expected: 0)" << std::endl;
    std::cout << "e == f: " << (e == f) << " (expected: 1)" << std::endl;
    std::cout << "e != f: " << (e != f) << " (expected: 0)" << std::endl;

    std::cout << "\nTesting min/max functions:" << std::endl;
    std::cout << "Fixed::min(c, d): " << Fixed::min(c, d) << " (expected: -10)" << std::endl;
    std::cout << "Fixed::min(a, b): " << Fixed::min(a, b) << " (expected: 0)" << std::endl;
    std::cout << "Fixed::max(c, d): " << Fixed::max(c, d) << " (expected: 10)" << std::endl;
    std::cout << "Fixed::max(a, b): " << Fixed::max(a, b) << " (expected: 10.10)" << std::endl;

	return 0;
}
