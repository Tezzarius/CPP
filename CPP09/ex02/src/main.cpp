#include "PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "no input" << std::endl;
		return 1;
	}

	std::vector<long> vec;
	std::deque<long> deque;

	for (int i = 1; av[i]; i++) {
		if (PmergeMe::parseInput(vec, deque, av[i]))
			return 1;
	}

	if (VERBOSE) {
		std::cout << "vector: ";
		for (size_t i = 0; i < vec.size(); i++)
			std::cout << vec.at(i) << " ";
		std::cout << std::endl << "deque:  ";
		for (size_t i = 0; i < deque.size(); i++)
			std::cout << deque.at(i) << " ";
		std::cout << std::endl;
	}

	return 0;
}