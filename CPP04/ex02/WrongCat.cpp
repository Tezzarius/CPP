#include "WrongCat.hpp"

WrongCat::WrongCat() {
	_type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << "WrongCat was copied" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	std::cout << "WrongCat was assigned" << std::endl;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat is destroyed" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "* WrongCat sound! *" << std::endl;
}
