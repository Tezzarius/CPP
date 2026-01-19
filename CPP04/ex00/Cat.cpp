#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Cat was copied" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	std::cout << "Cat was assigned" << std::endl;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat is destroyed" <<std::endl;
}

void Cat::makeSound() const {
	std::cout << "* Meow! Meow! *" << std::endl;
}
