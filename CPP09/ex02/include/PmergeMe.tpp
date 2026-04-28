#include "PmergeMe.hpp"

template <typename T>
void PmergeMe::fordJohnson(T &container) {
	if (container.size() <= 1)
		return;

	T mainChain;
	T pending;
	bool hasStraggler = (container.size() % 2 > 0) ? true : false;
	int straggler;

	if (hasStraggler) {
		straggler = container[container.size() - 1];
		container.pop_back();
	}

	for (size_t i = 0; i < container.size(); i += 2) {
		pending.push_back(std::min(container[i], container[i + 1]));
		mainChain.push_back(std::max(container[i], container[i + 1]));
	}

	fordJohnson(mainChain);

	// if (!pending.empty())
	// 	mainChain.insert(mainChain.begin(), pending[0]);

	std::vector<size_t> order = generateJacobsOrder(pending.size());

	for (size_t i = 0; i < order.size(); i++)
		binaryInsert(mainChain, pending[order[i]]);

	if (hasStraggler)
		binaryInsert(mainChain, straggler);

	container = mainChain;

	if (EXPLAIN) {
		std::cout << std::endl;
		for (size_t i = 0; i < mainChain.size(); i++)
			std::cout << mainChain[i] << " ";
		std::cout << std::endl;
	}
}

template <typename T>
void PmergeMe::binaryInsert(T &mainChain, int value) {
	size_t left = 0;
	size_t right = mainChain.size();
	size_t mid;

	while (left < right) {
		mid = (left + right) / 2;

		if (value < mainChain[mid])
			right = mid;
		else
			left = mid + 1;
	}

	mainChain.insert(mainChain.begin() + left, value);
}
