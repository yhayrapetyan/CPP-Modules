/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:31:30 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/04 19:52:57 by yuhayrap         ###   ########.fr       */
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

void Harl::complain(string level) {
	void (Harl::*ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	string complains[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++) {
		if (complains[i] == level) {
			(this->*ptr[i])();
			return;
		}
	}
}
