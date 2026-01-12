#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << name << " is constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
	std::cout << "ClapTrap " << name << " was copied" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	std::cout << "ClapTrap " << name << " assigned" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "Claptrap " << name << " is destroyed" << std::endl;
}

std::string ClapTrap::getName() const {
	return name;
}

unsigned int ClapTrap::getHitPoints() const {
	return hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
	return energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const {
	return attackDamage;
}

void ClapTrap::setName(std::string const name) {
	this->name = name;
}

void ClapTrap::setHitPoints(unsigned int amount) {
	this->hitPoints = amount;
}

void ClapTrap::setEnergyPoints(unsigned int amount) {
	this->energyPoints = amount;
}

void ClapTrap::setAttackDamage(unsigned int amount) {
	this->attackDamage = amount;
}

void ClapTrap::attack(const std::string &target) {
	if (hitPoints < 1) {
		std::cout << "ClapTrap " << name << " is dead and can't attack" << std::endl;
		return;
	}
	if (energyPoints < 1) {
		std::cout << "ClapTrap " << name << " has no energy to attack" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << " causing " << attackDamage << " points of damage!" << std::endl;
	energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << name << " takes " << amount << " damage";
	if (amount > hitPoints) {
		hitPoints = 0;
		std::cout << " and dies";
	}
	else {
		hitPoints -= amount;
	}
	std::cout << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (hitPoints < 1) {
		std::cout << "ClapTrap " << name << " is dead and can't repair itself" << std::endl;
		return;
	}
	if (energyPoints < 1) {
		std::cout << "ClapTrap " << name << " has no energy to repair itself" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " repairs itself, it regains " << amount << " hit points" << std::endl;
	energyPoints--;
	hitPoints += amount;
}