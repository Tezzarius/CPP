#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) {
	_rawBits = i * 256;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(f * 256);
}

Fixed::Fixed(const Fixed &other) : _rawBits(other._rawBits){
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other) {
		_rawBits = other._rawBits;
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Deconstructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "get_RawBits member function called" << std::endl;
	return _rawBits;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "set_RawBits member function called" <<std::endl;
	this->_rawBits = raw;
}

float Fixed::toFloat(void) const {
	return (float)_rawBits / 256;
}

int Fixed::toInt(void) const {
	return _rawBits / 256;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}