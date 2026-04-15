#include "PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "no input" << std::endl;
		return 1;
	}

	std::vector<long> vec;

	for (int i = 1; av[i]; i++) {
		if (parseInput(vec, av[i]))
			return 1;
	}

	if (VERBOSE) {
		for (size_t i = 0; i < vec.size(); i++)
			std::cout << vec.at(i) << " ";
		std::cout << std::endl;
	}

	return 0;
}