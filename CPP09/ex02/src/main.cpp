#include "PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Error: no input" << std::endl;
		return 1;
	}

	PmergeMe *johnson = NULL;

	try {
		johnson = new PmergeMe(av);
	} catch(const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	johnson->sortAndPrint();

	delete johnson;

	return 0;
}
