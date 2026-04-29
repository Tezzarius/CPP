#include "PmergeMe.hpp"

template <typename T>
void PmergeMe::fordJohnson(T &container, int depth) {
	if (container.size() <= 1)
		return;

	T mainChain;
	std::vector<Pair> pairs;
	bool hasStraggler = (container.size() % 2 != 0);
	long straggler;

	if (hasStraggler) {
		straggler = container[container.size() - 1];
		container.pop_back();
	}

	Pair pair;

	for (size_t i = 0; i + 1 < container.size(); i += 2) {
		if (container[i] < container[i + 1]) {
			pair.small = container[i];
			pair.large = container[i + 1];
		} 
		else {
			pair.small = container[i + 1];
			pair.large = container[i];
		}
		_comparisons++;
		pairs.push_back(pair);
		mainChain.push_back(pair.large);
	}

	if (_explain && EXPLAIN)
		explainBefore(container, hasStraggler, straggler, pairs, mainChain, depth);

	fordJohnson(mainChain, depth + 1);

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

	if (_explain && EXPLAIN)
		explainAfter(sortedPairs, mainChain, order, depth);

	for (size_t i = 1; i < order.size(); i++)
		binaryInsert(mainChain, sortedPairs[order[i]].small, findPosition(mainChain, sortedPairs[order[i]].large) + 1);

	if (hasStraggler)
		binaryInsert(mainChain, straggler, mainChain.size());

	container = mainChain;
}

template <typename T>
void PmergeMe::binaryInsert(T &mainChain, long value, size_t right) {
	size_t left = 0;
	size_t mid;

	while (left < right) {
		mid = (left + right) / 2;
		_comparisons++;
		if (value < mainChain[mid])
			right = mid;
		else
			left = mid + 1;
	}

	mainChain.insert(mainChain.begin() + left, value);
}

template <typename T>
size_t PmergeMe::findPosition(T &mainChain, long target) {
	size_t i;

	i = 0;
	while (i < mainChain.size()) {
		if (mainChain[i] == target)
			return (i);
		i++;
	}
	return (mainChain.size());
}
