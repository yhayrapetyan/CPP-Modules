#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

class DiamondTrap: public ScavTrap, public FragTrap {
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &diamondtrap);
	DiamondTrap &operator=(const DiamondTrap &diamontdrap);
	virtual ~DiamondTrap();

	using       ScavTrap::attack;
	void        whoAmI();

private:
	string _name;
};

#endif