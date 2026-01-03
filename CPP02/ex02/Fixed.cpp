#include "Fixed.hpp"

//constructor
Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) {
	rawBits = i * 256;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	rawBits = roundf(f * 256);
}

Fixed::Fixed(const Fixed &other) : rawBits(other.rawBits){
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
	rawBits = other.rawBits;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Deconstructor called" << std::endl;
}

// getter and setter
int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return rawBits;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" <<std::endl;
	this->rawBits = raw;
}

// convertions
float Fixed::toFloat(void) const {
	return (float)rawBits / 256;
}

int Fixed::toInt(void) const {
	return rawBits / 256;
}

// operator overloads
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

bool Fixed::operator>(const Fixed &other) const {
	return rawBits > other.rawBits;
}

bool Fixed::operator<(const Fixed &other) const {
	return rawBits < other.rawBits;
}

bool Fixed::operator>=(const Fixed &other) const {
	return rawBits >= other.rawBits;
}

bool Fixed::operator<=(const Fixed &other) const {
	return rawBits <= other.rawBits;
}

bool Fixed::operator==(const Fixed &other) const {
	return rawBits == other.rawBits;
}

bool Fixed::operator!=(const Fixed &other) const {
	return rawBits != other.rawBits;
}

Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->rawBits + other.rawBits);
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->rawBits - other.rawBits);
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;
	long tmp = (long)this->rawBits * (long)other.rawBits;
	result.setRawBits(tmp >> fractoralBits);
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed result;
	long tmp = ((long)this->rawBits << fractoralBits) / other.rawBits;
	result.setRawBits(tmp);
	return result;
}

Fixed &Fixed::operator++() {
	rawBits += 2^fractoralBits;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed old(*this);
	rawBits += 2^fractoralBits;
	return old;
}

Fixed &Fixed::operator--() {
	rawBits -= 2^fractoralBits;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed old(*this);
	rawBits -= 2^fractoralBits;
	return old;
}