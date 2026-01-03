#include "Fixed.hpp"

int main() {
	Fixed a;
	Fixed b(a);
	Fixed c;

	a.setRawBits(4);

	c = a;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}