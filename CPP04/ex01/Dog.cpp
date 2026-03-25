#include "Dog.hpp"

Dog::Dog() {
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	_brain = new Brain(*other._brain);
	std::cout << "Dog was copied" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	std::cout << "Dog was assigned" << std::endl;
	return *this;
}

Dog::~Dog() {
	delete _brain;
	std::cout << "Dog is destroyed" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "* Woof! Woof! *" << std::endl;
}
