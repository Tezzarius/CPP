#include "Zombie.hpp"

Zombie::Zombie() : name("Zombie") {
	std::cout << "Zombie is created" << std::endl;
}

Zombie::Zombie(std::string name) : name(name) {
	std::cout << name << " is created" << std::endl;
}

Zombie::Zombie(const Zombie &other) {
	name = other.name;
	std::cout << name << " was copied" << std::endl;
}

Zombie &Zombie::operator=(const Zombie &other) {
	if (this != &other) {
		name = other.name;
	}
	std::cout << name << " was assigned" << std::endl;
	return *this;
}

Zombie::~Zombie() {
	std::cout << name << " is destroyed" << std::endl;
}

void Zombie::announce() {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string& name) {
	this->name = name;
	std::cout << name << " is created" << std::endl;
}