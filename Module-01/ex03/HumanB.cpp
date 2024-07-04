/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:50:40 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/04 18:13:53 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(string name)//: _weapon()
{
	this->_name = name;
	this->_is_armed = false;
}

HumanB::~HumanB(void)
{
	
}

void	HumanB::attack(void)
{
	if (this->_is_armed)
		std::cout << this->_name << " attacks with their " \
			<< this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " attacks with his fists." << std::endl;
}
void    HumanB::setWeapon(Weapon &weapon)
{
	this->_is_armed =true;
	this->_weapon = &weapon;
}
