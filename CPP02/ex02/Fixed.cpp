#include "Fixed.hpp"

//constructor
Fixed::Fixed() : _rawBits(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) {
	_rawBits = i * (1 << _fractionalBits);
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(f * (1 << _fractionalBits));
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
	std::cout << "Destructor called" << std::endl;
}

// getter and setter
int Fixed::getRawBits(void) const {
	std::cout << "get_RawBits member function called" << std::endl;
	return _rawBits;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "set_RawBits member function called" <<std::endl;
	this->_rawBits = raw;
}

// convertions
float Fixed::toFloat(void) const {
	return (float)_rawBits / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
	return _rawBits / (1 << _fractionalBits);
}

// operator overloads
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

bool Fixed::operator>(const Fixed &other) const {
	return _rawBits > other._rawBits;
}

bool Fixed::operator<(const Fixed &other) const {
	return _rawBits < other._rawBits;
}

bool Fixed::operator>=(const Fixed &other) const {
	return _rawBits >= other._rawBits;
}

bool Fixed::operator<=(const Fixed &other) const {
	return _rawBits <= other._rawBits;
}

bool Fixed::operator==(const Fixed &other) const {
	return _rawBits == other._rawBits;
}

bool Fixed::operator!=(const Fixed &other) const {
	return _rawBits != other._rawBits;
}

Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->_rawBits + other._rawBits);
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->_rawBits - other._rawBits);
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;
	long tmp = (long)this->_rawBits * (long)other._rawBits;
	result.setRawBits(tmp >> _fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed result;
	if (other._rawBits == 0) {
		std::cout << "Error: division by zero" << std::endl;
		result.setRawBits(0);
		return result;
	}
	long tmp = ((long)this->_rawBits << _fractionalBits) / other._rawBits;
	result.setRawBits((int)tmp);
	return result;
}

Fixed &Fixed::operator++() {
	_rawBits += 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed old(*this);
	_rawBits += 1;
	return old;
}

Fixed &Fixed::operator--() {
	_rawBits -= 1;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed old(*this);
	_rawBits -= 1;
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