#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap("unknown Clap"){
	std::cout << "DiamondTrap Default constructor\n";
	this->_hit = FragTrap::_hit;
	this->_energy = ScavTrap::_energy;
	this->_damage = FragTrap::_damage;
	this->_name = "unknown Diamond";
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap Default destructor\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap) : ClapTrap(diamondtrap), ScavTrap(diamondtrap), FragTrap(diamondtrap) {//idk about this
	std::cout << "DiamondTrap Copy constructor\n";
	this->_name = diamondtrap._name;
	this->_hit = diamondtrap._hit;
	this->_energy = diamondtrap._energy;
	this->_damage = diamondtrap._damage;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondtrap) {
	std::cout << "DiamondTrap Copy assign constructor\n";
	this->_name = diamondtrap._name;
	this->_hit = diamondtrap._hit;
	this->_energy = diamondtrap._energy;
	this->_damage = diamondtrap._damage;
	ClapTrap::_name = diamondtrap.ClapTrap::_name;//idk about this
	return (*this);
}

DiamondTrap::DiamondTrap(string name) : ClapTrap(name) {
	std::cout << "DiamondTrap Main constructor\n";
	this->_hit = FragTrap::_hit;
	this->_energy = ScavTrap::_energy;
	this->_damage = FragTrap::_damage;
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
}

void DiamondTrap::whoAmI() {
	std::cout << this->_name << " : " << ClapTrap::_name << "\n";
}
