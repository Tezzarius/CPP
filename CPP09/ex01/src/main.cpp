#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Error: no input" << std::endl;
		return 1;
	}

	for (int i = 1; av[i]; i++) {
		if (RPN::reversePolishNotation(av[i]))
		 return 1;
	}

	return 0;
}