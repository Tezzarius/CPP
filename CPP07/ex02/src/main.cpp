#include <iostream>
#include "Array.hpp"

int main() {
	Array<int> a(5);

	for (unsigned int i = 0; i < a.size(); i++) {
		a[i] = i * 10;
	}

	for (unsigned int i = 0; i < a.size(); i++) {
		std::cout << a[i] << std::endl;
	}

	std::cout << "Copy test" << std::endl;

	Array<int> b = a;

	b[0] = 999;

	std::cout << "a[0]: " << a[0] << std::endl;
	std::cout << "b[0]: " << b[0] << std::endl;

	try {
		std::cout << a[10] << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception caught!" << std::endl;
	}
}