#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **av) {
	try {
		for (int i = 1; av[i]; i++)
			parseInput(av[i]);
	} catch(...) {
		throw;
	}
}

PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deq(other._deq) {
	
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {

}

void PmergeMe::sortAndPrint() {
	printContainer("Before: ");

	std::clock_t startVector = std::clock();
	fordJohnson(_vec);
	std::clock_t endVector = std::clock();
	double timeVector = 10.0 * (endVector - startVector) / CLOCKS_PER_SEC;

	std::clock_t startDeque = std::clock();
	fordJohnson(_deq);
	std::clock_t endDeque = std::clock();
	double timeDeque = 10.0 * (endDeque - startDeque) / CLOCKS_PER_SEC;

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
			_vec.push_back(num);
			_deq.push_back(num);
		}
		else
			throw std::runtime_error("Error: input number out of range");

		current = end;
	}
}

void PmergeMe::printContainer(std::string str) {
	int out = (_vec.size() < 11) ? _vec.size() : 4;

	std::cout << str;

	if (VERBOSE) {
		for (size_t i = 0; i < _vec.size(); i++)
			std::cout << _vec.at(i) << " ";
		std::cout << std::endl;
		return;
	}

	for (int i = 0; i < out; i++)
		std::cout << _vec.at(i) << " ";
	std::cout << ((_vec.size() < 11) ? "" : "[...]") << std::endl;
}

void PmergeMe::printResult(double timeVector, double timeDeque) {
	printContainer("After:  ");

	std::cout << std::fixed << std::setprecision(5)
			  << "Time to process a range of " << _vec.size() << " elements with std::vector : " << timeVector << " us" << std::endl
			  << "Time to process a range of " << _deq.size() << " elements with std::deque  : " << timeDeque << " us" << std::endl;
}

long PmergeMe::min(long &a, long &b) {
	return (a < b) ? a : b;
}

long PmergeMe::max(long &a, long &b) {
	return (a > b) ? a : b;
}
