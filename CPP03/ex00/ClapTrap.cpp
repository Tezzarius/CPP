#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " is constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
	std::cout << "ClapTrap " << _name << " was copied" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap " << _name << " assigned" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "Claptrap " << _name << " is destroyed" << std::endl;
}

std::string ClapTrap::getName() const {
	return _name;
}

unsigned int ClapTrap::getHitPoints() const {
	return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
	return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const {
	return _attackDamage;
}

void ClapTrap::setName(std::string const name) {
	this->_name = name;
}

void ClapTrap::setHitPoints(unsigned int amount) {
	this->_hitPoints = amount;
}

void ClapTrap::setEnergyPoints(unsigned int amount) {
	this->_energyPoints = amount;
}

void ClapTrap::setAttackDamage(unsigned int amount) {
	this->_attackDamage = amount;
}

void ClapTrap::attack(const std::string &target) {
	if (_hitPoints < 1) {
		std::cout << "ClapTrap " << _name << " is dead and can't attack" << std::endl;
		return;
	}
	if (_energyPoints < 1) {
		std::cout << "ClapTrap " << _name << " has no energy to attack" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << _name << " takes " << amount << " damage";
	if (amount > _hitPoints) {
		_hitPoints = 0;
		std::cout << " and dies";
	}
	else {
		_hitPoints -= amount;
	}
	std::cout << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints < 1) {
		std::cout << "ClapTrap " << _name << " is dead and can't repair itself" << std::endl;
		return;
	}
	if (_energyPoints < 1) {
		std::cout << "ClapTrap " << _name << " has no energy to repair itself" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " repairs itself, it regains " << amount << " hit points" << std::endl;
	_energyPoints--;
	_hitPoints += amount;
}