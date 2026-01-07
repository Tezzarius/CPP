#include "Zombie.hpp"

Zombie::Zombie() {
	// name bleibt leer
}

Zombie::Zombie(std::string name) {
	this->name = name;
	std::cout << name << " is created" << std::endl;
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