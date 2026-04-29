#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **av) : _explain(false), _comparisons(0) {
	try {
		for (int i = 1; av[i]; i++)
			parseInput(av[i]);
	} catch(...) {
		throw;
	}
}

PmergeMe::PmergeMe(const PmergeMe &other)
	: _vector(other._vector), _deque(other._deque), _explain(other._explain) , _comparisons(other._comparisons) {
	
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_vector = other._vector;
		_deque = other._deque;
		_explain = other._explain;
		_comparisons = other._comparisons;
	}
	return *this;
}

PmergeMe::~PmergeMe() {

}

void PmergeMe::sortAndPrint() {
	printContainer("Before: ");

	std::clock_t startVector = std::clock();
	fordJohnson(_vector, 0);
	std::clock_t endVector = std::clock();
	double timeVector = 1e6 * (endVector - startVector) / CLOCKS_PER_SEC;
	
	_comparisons = 0;
	std::clock_t startDeque = std::clock();
	fordJohnson(_deque, 0);
	std::clock_t endDeque = std::clock();
	double timeDeque = 1e6 * (endDeque - startDeque) / CLOCKS_PER_SEC;

	printResult(timeVector, timeDeque);
}

void PmergeMe::parseInput(const std::string &str) {
	if (str.empty())
		throw std::runtime_error("Error: no input");

	char *end;
	const char *current = str.c_str();
	
	while (*current != '\0') {
		long num = std::strtol(current, &end, 10);
		if ((*end != '\0' && *end != ' ') || current == end)
			throw std::runtime_error("Error: invalid character");
		
		if (num >= 0 && num <= INT_MAX) {
			_vector.push_back(num);
			_deque.push_back(num);
		}
		else
			throw std::runtime_error("Error: input number out of range");

		current = end;
	}
}

void PmergeMe::printContainer(std::string str) {
	int out = (_vector.size() < 11) ? _vector.size() : 4;

	std::cout << str;

	if (VERBOSE) {
		for (size_t i = 0; i < _vector.size(); i++)
			std::cout << _vector.at(i) << " ";
		std::cout << std::endl;
		return;
	}

	for (int i = 0; i < out; i++)
		std::cout << std::setw(5) << _vector.at(i) << " ";
	std::cout << ((_vector.size() < 11) ? "" : "[...]") << std::endl;
}

void PmergeMe::printResult(double timeVector, double timeDeque) {
	printContainer("After:  ");
	
	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << std::setw(4) << timeVector << " us" << std::endl
			  << "Time to process a range of " << _deque.size() << " elements with std::deque  : " << std::setw(4) << timeDeque << " us" << std::endl;
	if (VERBOSE)
		std::cout << "Comparisons used for " << _vector.size() << " elements: " << _comparisons << std::endl;
}

std::vector<size_t> PmergeMe::generateJacobsOrder(size_t size) {
	std::vector<size_t> order;
	std::vector<size_t> jacob;
	size_t a = 1;
	size_t b = 3;
	size_t next;
	size_t prev = 0;
	size_t current;

	if (size == 0)
		return order;

	jacob.push_back(1);

	while (b < size) {
		jacob.push_back(b);
		next = b + (2 * a);
		a = b;
		b = next;
	}

	for (size_t i = 0; i < jacob.size(); i++) {
		current = jacob[i];

		for (size_t  j = current; j > prev; j--)
			order.push_back(j - 1);
		
		prev = current;
	}

	for (size_t i = prev; i < size; i++)
		order.push_back(i);

	return order;
}
