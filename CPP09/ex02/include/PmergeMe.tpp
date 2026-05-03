#include "PmergeMe.hpp"


#include "PmergeMe.hpp"

// Ford-Johnson/Merge-Insertion Sort, garantiert ≤66 Vergleiche für 21 Elemente
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

	size_t debug_start = _comparisons;
	// 1. Paare bilden (immer nur EIN Vergleich pro Paar!)
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

	if (depth == 0) std::cout << "[DEBUG] Nach Pairing: " << (_comparisons-debug_start) << " Vergleiche, gesamt: " << _comparisons << std::endl;

	// 2. Rekursiv große Elemente sortieren
	fordJohnson(mainChain, depth + 1);

	// 3. Paare den sortierten großen Elementen zuordnen
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

	// 4. Jacobsthal-Reihenfolge für kleine Elemente
	std::vector<size_t> order = generateJacobsOrder(sortedPairs.size());

	// 5. Kleine Elemente einfügen
	debug_start = _comparisons;
	for (size_t k = 0; k < order.size(); ++k) {
		size_t idx = order[k];
		long small = sortedPairs[idx].small;
		size_t right = findPosition(mainChain, sortedPairs[idx].large);
		if (k == 0) {
			// Das erste kleine Element ohne Vergleich exakt links vom zugehörigen large einfügen
			mainChain.insert(mainChain.begin() + right, small);
		} else {
			binaryInsert(mainChain, small, right);
		}
	}
	if (depth == 0) std::cout << "[DEBUG] Nach kleine Zahlen: " << (_comparisons-debug_start) << " Vergleiche, gesamt: " << _comparisons << std::endl;

	// 6. Straggler einsortieren (immer am Ende)
	debug_start = _comparisons;
	if (hasStraggler) {
		size_t smallEnd = order.size();
		if (mainChain.empty() || straggler > mainChain.back()) {
			std::cout << "[DEBUG] Straggler hinten: " << straggler << std::endl;
			mainChain.push_back(straggler); // Kein Vergleich nötig
		} else {
			std::cout << "[DEBUG] Straggler binär: " << straggler << " in [";
			for (size_t i = 0; i < mainChain.size(); ++i) std::cout << mainChain[i] << (i+1<mainChain.size()? ", ":"");
			std::cout << "] bis " << smallEnd << std::endl;
			binaryInsert(mainChain, straggler, smallEnd);
		}
	}
	if (depth == 0 && hasStraggler) std::cout << "[DEBUG] Nach Straggler: " << (_comparisons-debug_start) << " Vergleiche, gesamt: " << _comparisons << std::endl;

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
