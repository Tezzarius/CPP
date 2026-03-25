#include "Cat.hpp"

Cat::Cat() {
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	_brain = new Brain(*other._brain);
	std::cout << "Cat was copied" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	std::cout << "Cat was assigned" << std::endl;
	return *this;
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat is destroyed" <<std::endl;
}

void Cat::makeSound() const {
	std::cout << "* Meow! Meow! *" << std::endl;
}
