#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Default constructor for Brain\n";
	this->_ideas = new string[100];
}

Brain::~Brain() {
	std::cout << "Destructor for Brain\n";
	delete[] this->_ideas;
}

Brain::Brain(const Brain &other) {
	std::cout << "Copy constructor for Brain\n";
	this->_ideas = new std::string[100];
	for (unsigned int i = 0; i < 100; ++i)
		this->_ideas[i] = other._ideas[i];
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << "Copy assignment operator for Brain\n";
	if (this != &other) {
		delete[] this->_ideas;
		this->_ideas = new std::string[100];
		for (unsigned int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return (*this);
}

string &Brain::operator[](unsigned int i) { return (this->_ideas[i]); }