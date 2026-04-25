#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Error: no input" << std::endl;
		return 1;
	}

	std::stack<int, std::list<int> > list;
	std::string str = av[1];

	for (int i = 2; av[i]; i++) {
		str += " ";
		str += av[i];
	}

	if (RPN::reversePolishNotation(list, str))
		return 1;

	return 0;
}