#include "Fixed.hpp"

//constructor
Fixed::Fixed() : rawBits(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) {
	rawBits = i * (1 << fractionalBits);
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	rawBits = roundf(f * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &other) : rawBits(other.rawBits){
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other) {
		rawBits = other.rawBits;
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
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
	return (float)rawBits / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
	return rawBits / (1 << fractionalBits);
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
	result.setRawBits(tmp >> fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed result;
	if (other.rawBits == 0) {
		std::cout << "Error: division by zero" << std::endl;
		result.setRawBits(0);
		return result;
	}
	long tmp = ((long)this->rawBits << fractionalBits) / other.rawBits;
	result.setRawBits((int)tmp);
	return result;
}

Fixed &Fixed::operator++() {
	rawBits += 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed old(*this);
	rawBits += 1;
	return old;
}

Fixed &Fixed::operator--() {
	rawBits -= 1;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed old(*this);
	rawBits -= 1;
	return old;
}

Fixed &Fixed::min(Fixed& a, Fixed& b) {
	if (a < b)
		return a;
	return b;
}

Fixed const &Fixed::min(const Fixed& a, const Fixed& b) {
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed& a, Fixed& b) {
	if (a > b)
		return a;
	return b;
}

Fixed const &Fixed::max(const Fixed& a, const Fixed& b) {
	if (a > b)
		return a;
	return b;
}