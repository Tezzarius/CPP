#include "PmergeMe.hpp"

template <typename T>
void PmergeMe::fordJohnson(T &container) {
	if (container.size() < 1)
		return;

	T mainChain;
	T pending;
	std::vector<Pair> pairs;
	bool hasStraggler = (container.size() % 2 > 0) ? true : false;
	int straggler;

	if (hasStraggler) {
		straggler = container[container.size() - 1];
		container.pop_back();
	}

	for (size_t i = 0; i < container.size(); i += 2) {
		Pair p;
		p.small = min(container[i], container[i + 1]);
		p.large = max(container[i], container[i + 1]);
		pairs.push_back(p);
	}

	for (size_t i = 0; i < pairs.size(); i++) {
		pending.push_back(pairs[i].small);
		mainChain.push_back(pairs[i].large);
	}

	container.clear();

	for (size_t i = 0; i < pending.size(); i++) {
		container.push_back(pending[i]);
		container.push_back(mainChain[i]);
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
