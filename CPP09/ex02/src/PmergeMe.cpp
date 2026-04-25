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
			_input.push_back(num);
			_vec.push_back(num);
			_deq.push_back(num);
		}
		else
			throw std::runtime_error("Error: input number out of range");

		current = end;
	}
}

void PmergeMe::fordJohnsonVector(std::vector<long> &vec) {
	(void) vec;
}

void PmergeMe::printOutput() {
	int out = (_input.size() < 11) ? _input.size() : 4;

	std::cout << "Before:  ";
	for (int i = 0; i < out; i++)
		std::cout << _input.at(i) << " ";
	std::cout << ((_input.size() < 11) ? "" : "[...]") << std::endl << "After:   ";
	for (int i = 0; i < out; i++)
		std::cout << _vec.at(i) << " ";
	std::cout << ((_vec.size() < 11) ? "" : "[...]") << std::endl;
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << std::endl
			  << "Time to process a range of " << _deq.size() << " elements with std::deque  : " << std::endl;

	if (VERBOSE) {
		std::cout << std::endl << "vector:  ";
		for (size_t i = 0; i < _vec.size(); i++)
		std::cout << _vec.at(i) << " ";
		std::cout << std::endl << "deque:   ";
		for (size_t i = 0; i < _deq.size(); i++)
		std::cout << _deq.at(i) << " ";
		std::cout << std::endl;
	}
}