#include "Data.hpp"

Data::Data() : value(0) {
    // std::cout << "Default constructor called\n";
}

Data::~Data() {
    // std::cout << "Destructor called\n";
}

Data::Data(const Data &copy) : value(copy.value) {
    // std::cout << "Copy constructor called\n";
}

Data &Data::operator=(const Data &other) {
    // std::cout << "Copy assignment operator called\n";
    if (this != &other) {
        value = other.value;
    }
    return *this;
}
