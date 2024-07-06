/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:08:21 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/07/05 20:30:57 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
	std::cout << "ClapTrap Default constructor\n";
	this->_hit = 10;
	this->_energy = 10;
	this->_damage = 0;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap Default destructor\n";
}

ClapTrap::ClapTrap(const ClapTrap &claptrap) {
	std::cout << "ClapTrap Copy constructor\n";
	this->_name = claptrap._name;
	this->_hit = claptrap._hit;
	this->_energy = claptrap._energy;
	this->_damage = claptrap._damage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap) {
	std::cout << "ClapTrap Copy assign constructor\n";
	this->_name = claptrap._name;
	this->_hit = claptrap._hit;
	this->_energy = claptrap._energy;
	this->_damage = claptrap._damage;
	return (*this);
}

ClapTrap::ClapTrap(string name) {
	std::cout << "ClapTrap Main constructor\n";
	this->_hit = 10;
	this->_energy = 10;
	this->_damage = 0;
	this->_name = name;
}

void ClapTrap::attack(const string &target) {
	if (0 == this->_energy || 0 == this->_hit)
		return;
	this->_energy--;
	std::cout << this->_name << " attacs " << target;
	if (this->_damage > 0)
		std::cout << " causing " << this->_damage << " damage\n";
	else
		std::cout << " causing no damage\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
	this->_hit -= amount;
	std::cout << this->_name << " taking " << amount << " damage ";
	if (this->_hit <= 0) {
		this->_hit = 0;
		std::cout << "and dies\n";
	} else {
		std::cout << "and has " << this->_hit << " health\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (0 == this->_energy || 0 == this->_hit)
		return;
	this->_energy--;
	this->_hit += amount;
	std::cout << this->_name << " was healed and now have " << this->_hit << " health\n";
}
