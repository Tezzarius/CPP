#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "This programm needs a file!" << std::endl;
		return 1;
	}

	std::ifstream fd(av[1]);
	if (!fd.is_open()) {
		std::cerr << "Error: Can't open " << av[1] << "!" << std::endl;
		return 1;
	}

	if (checkData()) {
		return 1;
	}

	std::cout << "Success!" << std::endl;
	return 0;
}