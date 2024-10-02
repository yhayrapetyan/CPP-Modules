/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:31:30 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/10/02 15:22:56 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {
}

Harl::~Harl(void) {
}

void Harl::debug(void) { std::cout << "DEBUG message" << std::endl; }
void Harl::info(void) { std::cout << "INFO message" << std::endl; }
void Harl::warning(void) { std::cout << "WARNING message" << std::endl; }
void Harl::error(void) { std::cout << "ERROR message" << std::endl; }


static int	get_level(string level)
{
	string complains[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (complains[i] == level) {
			return (i);
		}
	}
	return (-1);
}

void Harl::complain(string level) {
	void (Harl::*ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	int int_level = get_level(level);
	switch (int_level)
	{
		case 0:
			(this->*ptr[0])();
			break;
		case 1:
			(this->*ptr[1])();
			break;
		case 2:
			(this->*ptr[2])();
			break;
		case 3:
			(this->*ptr[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems. ]\n";
			break ;
	}
}
