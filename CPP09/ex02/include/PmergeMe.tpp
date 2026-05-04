#include "PmergeMe.hpp"

template <typename T>
void PmergeMe::fordJohnson(T &container, int depth) {
	if (container.size() <= 1)
		return;

	T mainChain;
	std::vector<Pair> pairs;
	bool hasStraggler = (container.size() % 2 != 0);
	long straggler = 0;
	if (hasStraggler) {
		straggler = container.back();
		container.pop_back();
	}

	for (size_t i = 0; i + 1 < container.size(); i += 2) {
		Pair pair;
		_comparisons++;
		if (container[i] < container[i + 1]) {
			pair.small = container[i];
			pair.large = container[i + 1];
		} else {
			pair.small = container[i + 1];
			pair.large = container[i];
		}
		pairs.push_back(pair);
		mainChain.push_back(pair.large);
	}

	if (_explain && EXPLAIN) explainBefore(container, hasStraggler, straggler, pairs, mainChain, depth);

	fordJohnson(mainChain, depth + 1);

	std::vector<Pair> sortedPairs;
	std::vector<int> used(pairs.size(), 0);

	for (size_t i = 0; i < mainChain.size(); i++) {
		for (size_t j = 0; j < pairs.size(); j++) {
			if (!used[j] && mainChain[i] == pairs[j].large) {
				sortedPairs.push_back(pairs[j]);
				used[j] = 1;
				break;
			}
		}
	}

	std::vector<size_t> order = generateJacobsOrder(sortedPairs.size());

	if (_explain && EXPLAIN) explainAfter(sortedPairs, mainChain, order, depth);

	for (size_t i = 0; i < order.size(); ++i) {
		long small = sortedPairs[order[i]].small;
		size_t right = findPosition(mainChain, sortedPairs[order[i]].large);

		if (i == 0)
			mainChain.insert(mainChain.begin() + right, small);
		else
			binaryInsert(mainChain, small, right);
	}

	if (hasStraggler) {
		if (mainChain.empty() || straggler > mainChain.back())
			mainChain.push_back(straggler);
		else
			binaryInsert(mainChain, straggler, order.size());
	}

	container = mainChain;
}

template <typename T>
void PmergeMe::binaryInsert(T &mainChain, long value, size_t right) {
	size_t left = 0;
	while (left < right) {
		size_t mid = left + (right - left) / 2;
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
	for (size_t i = 0; i < mainChain.size(); ++i) {
		if (mainChain[i] == target)
			return i;
	}
	return mainChain.size();
}
