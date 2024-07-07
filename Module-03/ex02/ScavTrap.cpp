#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	std::cout << "ScavTrap Default constructor\n";
	this->_hit = 100;
	this->_energy = 50;
	this->_damage = 20;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap Default destructor\n";
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap) : ClapTrap(scavtrap) {//idk about this
	std::cout << "ScavTrap Copy constructor\n";
	this->_name = scavtrap._name;
	this->_hit = scavtrap._hit;
	this->_energy = scavtrap._energy;
	this->_damage = scavtrap._damage;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap) {
	std::cout << "ScavTrap Copy assign constructor\n";
	this->_name = scavtrap._name;
	this->_hit = scavtrap._hit;
	this->_energy = scavtrap._energy;
	this->_damage = scavtrap._damage;
	return (*this);
}

ScavTrap::ScavTrap(string name) : ClapTrap(name) {
	std::cout << "ScavTrap Main constructor\n";
	this->_hit = 100;
	this->_energy = 50;
	this->_damage = 20;
	this->_name = name;
}

void ScavTrap::attack(const string &target) {
	if (0 == this->_energy || 0 == this->_hit)
		return;
	this->_energy--;
	std::cout << this->_name << " ScavTrap attacks " << target;
	if (this->_damage > 0)
		std::cout << " causing " << this->_damage << " damage\n";
	else
		std::cout << " causing no damage\n";
}

void ScavTrap::guardGate(void) {
	std::cout << this->_name << " has entered Gate keeper mode.\n";
}
