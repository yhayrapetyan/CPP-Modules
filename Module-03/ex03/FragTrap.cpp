#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	std::cout << "FragTrap Default constructor\n";
	this->_hit = 100;
	this->_energy = 100;
	this->_damage = 30;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap Default destructor\n";
}

FragTrap::FragTrap(const FragTrap &fragtrap) : ClapTrap(fragtrap) {//idk about this
	std::cout << "FragTrap Copy constructor\n";
	this->_name = fragtrap._name;
	this->_hit = fragtrap._hit;
	this->_energy = fragtrap._energy;
	this->_damage = fragtrap._damage;
}

FragTrap &FragTrap::operator=(const FragTrap &fragtrap) {
	std::cout << "FragTrap Copy assign constructor\n";
	this->_name = fragtrap._name;
	this->_hit = fragtrap._hit;
	this->_energy = fragtrap._energy;
	this->_damage = fragtrap._damage;
	return (*this);
}

FragTrap::FragTrap(string name) : ClapTrap(name) {
	std::cout << "FragTrap Main constructor\n";
	this->_hit = 100;
	this->_energy = 100;
	this->_damage = 30;
	this->_name = name;
}

void FragTrap::highFivesGuys() {
	std::cout << this->_name << " calls High Five members\n";
}