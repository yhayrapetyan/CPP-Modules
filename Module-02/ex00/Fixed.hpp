/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:13:38 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/05 15:31:21 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed &fixed);
        Fixed &operator=(const Fixed &fixed);
		
		void    setRawBits(int const raw);
		int		getRawBits(void) const;
	
	private:
		int			_fixPointNb;
		static int	_fractionalBitNB;
};

#endif