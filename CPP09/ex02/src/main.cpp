#include "PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "no input" << std::endl;
		return 1;
	}

	std::vector<long> vec;
	std::list<long> lst;

	for (int i = 1; av[i]; i++) {
		if (PmergeMe::parseInput(vec, lst, av[i]))
			return 1;
	}

	if (VERBOSE) {
		std::cout << "vector: ";
		for (size_t i = 0; i < vec.size(); i++)
			std::cout << vec.at(i) << " ";
		std::cout << std::endl << "list:   ";
		for (std::list<long>::iterator it = lst.begin(); it != lst.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	return 0;
}