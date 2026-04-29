#include "PmergeMe.hpp"

template <typename T>
void PmergeMe::explainBefore(T &container, bool hasStraggler, int straggler, std::vector<Pair> &pairs, T &mainChain, int depth) {
	std::cout << std::endl;
	printIndent(depth);

	std::cout << GREY << "Container: ";
	for (size_t i = 0; i < container.size(); i++)
		std::cout << container[i] << " ";
	std::cout << std::endl;

	if (hasStraggler) {
		printIndent(depth);
		std::cout << "Straggler: " << straggler << std::endl;
	}

	printIndent(depth);
	std::cout << "Pairs: ";
	for (size_t i = 0; i < pairs.size(); i++)
		std::cout << GREEN << "[" << pairs[i].small << ", " << pairs[i].large << "] " << GREY;
		
	std::cout << std::endl;

	printIndent(depth);
	std::cout << "Main chain before recursion: ";
	for (size_t i = 0; i < mainChain.size(); i++)
		std::cout << mainChain[i] << " ";
	std::cout << std::endl;

	printIndent(depth);
	std::cout << "Recursive sort ->" << RESET << std::endl;
}

template <typename T>
void PmergeMe::explainAfter(std::vector<Pair> &sortedPairs, T &mainChain, std::vector<size_t> &order, int depth) {
	std::cout << std::endl;
	printIndent(depth);

	std::cout << GREY << "Main chain after recursion: ";
	for (size_t i = 0; i < mainChain.size(); i++)
		std::cout << mainChain[i] << " ";
	std::cout << std::endl;

	printIndent(depth);
	std::cout << "Sorted pairs: ";
	for (size_t i = 0; i < sortedPairs.size(); i++)
		std::cout << GREEN << "[" << sortedPairs[i].small << ", " << sortedPairs[i].large << "] " << GREY;

	std::cout << std::endl;

	printIndent(depth);
	std::cout << "Insert order (Jacobsthal): ";
	for (size_t i = 0; i < order.size(); i++)
		std::cout << order[i] << " ";
	std::cout << RESET << std::endl;
}
