#include "PmergeMe.hpp"

template <typename T>
void PmergeMe::fordJohnson(T &container) {
	if (container.size() < 1)
		return;

	std::vector<Pair> pairs;
	bool hasStraggler = (container.size() % 2 > 0) ? true : false;
	int straggler;

	if (hasStraggler) {
		straggler = container[container.size() - 1];
		container.pop_back();
	}

	for (size_t i = 0, j = 0; i < container.size(); i += 2, j++) {
		Pair p;
		p.small = min(container[i], container[i + 1]);
		p.large = max(container[i], container[i + 1]);
		pairs.push_back(p);
	}

	for (size_t i = 0; i < pairs.size(); i++) {
		for (size_t j = 0; j < pairs.size() - 1 && pairs[j].large > pairs[j + 1].large; j++) {
			Pair tmp = pairs[j];
			pairs[j] = pairs[j + 1];
			pairs[j + 1] = tmp;
		}
	}

	for (size_t i = 0, j = 0; i < pairs.size(); i++, j += 2) {
		container[j] = pairs[i].small;
		container[j + 1] = pairs[i].large;
	}

	if (VERBOSE) {
		std::cout << std::endl;
		for (size_t i = 0; i < pairs.size(); i++) {
			std::cout << "Pair " << i << ": " << pairs[i].small << ", " << pairs[i].large << std::endl;
		}
		if (hasStraggler)
			std::cout << "Straggler: " << straggler << std::endl;
		
		std::cout << std::endl;
	}
}
