#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Default constructor for Brain\n";
}

Brain::~Brain() {
	std::cout << "Destructor for Brain\n";
}

Brain::Brain(const Brain &other) {
	std::cout << "Copy constructor for Brain\n";
	for (unsigned int i = 0; i < 100; ++i)
		this->_ideas[i] = other._ideas[i];
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << "Copy assignment operator for Brain\n";
	if (this != &other) {
		for (unsigned int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return (*this);
}

string &Brain::operator[](unsigned int i) { 
	if(i > 99) {
		throw std::out_of_range("Index is out of range\n");
	}
	return (this->_ideas[i]); 
}

void	Brain::set_idea(string idea, unsigned int i) {
	if (i > 99) {
		throw std::out_of_range("Index is out of range\n");
	}
	else
		this->_ideas[i] = idea; 
}

string	Brain::get_idea(unsigned int i) {
	if (i > 99) {
		throw std::out_of_range("Index is out of range\n");
	}
	return	this->_ideas[i]; 
}