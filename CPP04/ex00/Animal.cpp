#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &other) {
	type = other.type;
	std::cout << "Animal was copied" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
	if (this != &other) {
		type = other.type;
	}
	std::cout << "Animal assigned" << std::endl;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal is destroyed" << std::endl;
}

std::string Animal::getType() const {
	return type;
}

void Animal::makeSound() const {
	std::cout << "* Typical animal sound! *" << std::endl;
}
