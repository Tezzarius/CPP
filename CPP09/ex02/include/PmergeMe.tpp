#include "PmergeMe.hpp"

template <typename T>
void PmergeMe::fordJohnson(T &container) {
	if (container.size() <= 1)
		return;

	T mainChain;
	std::vector<Pair> pairs;
	bool hasStraggler = (container.size() % 2 != 0);
	int straggler;

	if (hasStraggler) {
		straggler = container[container.size() - 1];
		container.pop_back();
	}

	Pair pair;

	for (size_t i = 0; i < container.size(); i += 2) {
		pair.small = std::min(container[i], container[i + 1]);
		pair.large = std::max(container[i], container[i + 1]);
		pairs.push_back(pair);
		mainChain.push_back(pair.large);
	}

	fordJohnson(mainChain);

	std::vector<Pair> sortedPairs;
	std::vector<int> used(pairs.size(), 0);

	for (size_t i = 0; i < mainChain.size(); i++) {
		for (size_t j = 0; j < pairs.size(); j++) {
			if (used[j] == 0 && mainChain[i] == pairs[j].large) {
				sortedPairs.push_back(pairs[j]);
				used[j] = 1;
				break;
			}
		}
	}
	
	if (!sortedPairs.empty())
		mainChain.insert(mainChain.begin(), sortedPairs[0].small);

	std::vector<size_t> order = generateJacobsOrder(sortedPairs.size());

	for (size_t i = 1; i < order.size(); i++)
		binaryInsert(mainChain, sortedPairs[order[i]].small, findPosition(mainChain, sortedPairs[order[i]].large) + 1);

	if (hasStraggler)
		binaryInsert(mainChain, straggler, mainChain.size());

	container = mainChain;

	if (EXPLAIN) {
		std::cout << std::endl;
		for (size_t i = 0; i < mainChain.size(); i++)
			std::cout << mainChain[i] << " ";
		std::cout << std::endl;
	}
}

template <typename T>
void PmergeMe::binaryInsert(T &mainChain, int value, size_t right) {
	size_t left = 0;
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

template <typename T>
size_t PmergeMe::findPosition(T &mainChain, int target) {
	for (size_t i = 0; i < mainChain.size(); i++)
		if (mainChain[i] == target)
			return i;
	return mainChain.size();
}
