#include "BitcoinExchange.hpp"

int mapingData(std::ifstream &fd) {
	(void)fd;
	return 0;
}

int checkData() {
	std::ifstream fd("data.csv");
	if (!fd.is_open()) {
		std::cerr << "Error: Can't open data.csv!" << std::endl;
		return 1;
	}

	std::string str;

	std::getline(fd, str);
	if (str.compare("date,exchange_rate")) {
		std::cerr << "Error: Expected \"date,exchange_rate\" at the beginning of data.csv!" << std::endl;
		return 1;
	}

	while (std::getline(fd, str)) {
		if (str.empty()) {
			continue;
		}

		char *end;

		int year = std::strtol(str.c_str(), &end, 10);
		if (year < 2009 || year > 2026 || *end != '-' || str.at(4) != *end) {
			std::cerr << "Error: Wrong year format in data.csv!" << std::endl;
			return 1;
		}

		int month = std::strtol(end + 1, &end, 10);
		if (month < 1 || month > 12 || *end != '-' || str.at(7) != *end) {
			std::cerr << "Error: Wrong month format in data.csv!" << std::endl;
			return 1;
		}

		int day = std::strtol(end + 1, &end, 10);
		if (*end != ',' || str.at(10) != *end) {
			std::cerr << "Error: Wrong day format in data.csv!" << std::endl;
			return 1;
		}
		
		switch (month) {
			case 1: case 3: case 5: case 7: case 8: case 10: case 12: {
				if (day < 1 || day > 31) {
					std::cerr << "Error: Day out of range 31!" << std::endl;
					return 1;
				}
				break;
			}
			case 4: case 6: case 9: case 11: {
				if (day < 1 || day > 30) {
					std::cerr << "Error: Day out of range 30!" << std::endl;
					return 1;
				}
				break;
			}
			case 2: {
				int maxDay = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 29 : 28;
				if (day < 1 || day > maxDay) {
					std::cerr << "Error: Day out of range 28/29!" << std::endl;
					return 1;
				}
				break;
			}
			default:
				return 1;
		}

		int exRate = std::strtof(end + 1, &end);
		if (*end != '\0') {
			std::cerr << "Error: Wrong exchange rate format!" << std::endl;
			return 1;
		}
		(void)exRate;
	}
	if (mapingData(fd)) {
		std::cerr << "Error: Failed to map data.csv!" << std::endl;
	}
	return 0;
}