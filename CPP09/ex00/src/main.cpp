#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	std::ifstream fd(av[1]);
	if (!fd.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return 2;
	}

	std::map<std::string, double> data;

	if (BitcoinExchange::mappingData(data)) {
		return 3;
	}
	
	if (VERBOSE) {
		std::map<std::string, double>::iterator it;
		for (it = data.begin(); it != data.end(); ++it) {
			std::cout << std::fixed << std::setprecision(2) << it->first << " => " << it->second << std::endl;
		}
		std::cout << std::endl;
	}

	if (BitcoinExchange::exchange(data, fd)) {
		return 4;
	}

	return 0;
}