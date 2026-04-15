#include <iostream>
#include "Span.hpp"

int main() {
	try {
		Span sp(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "---------------------" << std::endl;

	try {
		Span sp(2);
		sp.addNumber(42);

		std::cout << sp.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Expected error: " << e.what() << std::endl;
    }

	std::cout << "---------------------" << std::endl;

	try {
		Span sp(3);

		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.addNumber(4);
	} catch (std::exception &e) {
		std::cerr << "Overflow error: " << e.what() << std::endl;
	}

	std::cout << "---------------------" << std::endl;

	try {
		Span sp(20000);
		std::vector<int> v;

		for (int i = 0; i < 20000; i++)
			v.push_back(i);
		sp.addRange(v.begin(), v.end());

		std::cout << "Big test shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Big test longest: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Big test error: " << e.what() << std::endl;
	}

	return 0;
}
