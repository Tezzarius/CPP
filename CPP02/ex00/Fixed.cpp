#include "Fixed.hpp"

Fixed::Fixed() : rawBits(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : rawBits(other.rawBits) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
	rawBits = other.rawBits;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Fixed::~Fixed() {
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return rawBits;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" <<std::endl;
	this->rawBits = raw;
}