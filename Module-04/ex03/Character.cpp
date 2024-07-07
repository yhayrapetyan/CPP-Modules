#include "Character.hpp"

Character::Character() {
	this->_name = "unknown character";
	this->_size = 0;
	std::cout <<"Default constructor for Character [" << this->_name << "]\n";
}

Character::~Character() {
	std::cout << "Destructor for Character" << this->_name << "\n";
//	for (int i = 0; i < 4; i++)//idk about this
//		this->_inventory[i] = NULL;
	for (int i = 0; i < this->_size; i++)
		delete this->_inventory[i];
}

Character::Character(const Character &other) {
	std::cout << "Copy constructor for Character\n";
	this->_name = other._name;
	this->_size = other._size;
	for (int i = 0; i < this->_size; ++i)
		this->_inventory[i] = other._inventory[i]->clone();
}

Character &Character::operator=(const Character &other) {
	std::cout << "Copy assignment operator for Character\n";
	for (int i = 0; i < this->_size; i++)
		delete this->_inventory[i];
	this->_name = other._name;
	this->_size = other._size;
	for (int i = 0; i < this->_size; ++i)
		this->_inventory[i] = other._inventory[i]->clone();
	return (*this);
}

Character::Character(std::string const &name) {
	this->_size = 0;
	this->_name = name;
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	std::cout << "Type constructor for Character [" << this->_name << "]\n";
}

std::string const &Character::getName() const { return this->_name; }

void Character::equip(AMateria *item) {
	if (!item){
		std::cout << "Error No Item\n";
		return;
	}
	if (this->_size < 4) {
		this->_inventory[(this->_size)++] = item;
		std::cout << "[" << item->getType() << "] equipped in inventory in index [" << this->_size - 1 << "]\n";
	} else
		std::cout << "No place left only 4 items\n";
}

void Character::unequip(int i) {
	if (i < 4 && !this->_inventory[i])
		std::cout << "Can't unequipped the empty inventory in index [" << i << "]\n";
	else if (i > 3)
		std::cout << "ERROR you can unequipped only 4 inventory, wrong index [" << i << "]\n";
	if (i >= 0 && i < this->_size) {
		if (i < this->_size) {
			std::cout << "[" << this->_name << "]" << " unequipped from inventory index [" << i << "]\n";
//			delete this->_inventory[i];
			while (this->_inventory[i + 1]) {
				this->_inventory[i] = this->_inventory[i + 1];
				i++;
			}
			this->_inventory[i] = 0;
			this->_size -= 1;
		}
	}
}

void Character::use(int i, ICharacter &target) {
	if (i < 4 && !this->_inventory[i])
		std::cout << "Empty inventory in index " << "[" << i << "]\n";
	else if (i > 3)
		std::cout<< "ERROR you can use only 4 inventory, wrong index [" << i << "]\n";
	if (i >= 0 && i < this->_size)
		this->_inventory[i]->use(target);
}