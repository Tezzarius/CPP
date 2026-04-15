#include "PmergeMe.hpp"

int parseInput(std::vector<long> &vec, std::string str) {
	if (str.empty()) {
		std::cerr << "Error: no input" << std::endl;
		return 1;
	}

	char *end;
	
	const char *current = str.c_str();
	while (*current != '\0') {
		long num = std::strtol(current, &end, 10);
		if (*end != '\0' && *end != ' ') {
			std::cerr << "Error: invalid character" << std::endl;
			return 1;
		}
		
		if (num >= 0 && num <= INT_MAX) {
			vec.push_back(num);
		}
		else {
			std::cerr << "Error: input number out of range" << std::endl;
			return 1;
		}
		current = end;
	}
	return 0;
}