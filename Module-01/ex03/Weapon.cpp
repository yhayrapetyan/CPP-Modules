/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:07:53 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/04 17:37:38 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(string type) {
	this->_type = type;
}

Weapon::~Weapon(void) {

}

string	 Weapon::getType(void) { return this->_type; }
void	 Weapon::setType(string type) { this->_type = type; }