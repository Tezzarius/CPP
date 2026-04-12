#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Error: no input" << std::endl;
		return 1;
	}

	std::stack<int> s;

	try {
		reversePolishNotation(s, av);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}