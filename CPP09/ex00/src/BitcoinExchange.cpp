#include "BitcoinExchange.hpp"

int BitcoinExchange::validateDate(std::string &str, double &value) {
	char *end;

	if (str.length() < 10) {
		std::cerr << "Error: bad input => " << str.substr(0 ,10) << std::endl;
		return 1;
	}

	int year = std::strtol(str.c_str(), &end, 10);
	if (*end != '-' || str.at(4) != *end) {
		std::cerr << "Error: bad input => " << str << std::endl;
		return 1;
	}

	int month = std::strtol(end + 1, &end, 10);
	if (month < 1 || month > 12 || *end != '-' || str.at(7) != *end) {
		std::cerr << "Error: bad input => " << str.substr(0 ,10) << std::endl;
		return 1;
	}

	int day = std::strtol(end + 1, &end, 10);
	if ((*end != ',' && *end != ' ') || str.at(10) != *end) {
		std::cerr << "Error: bad input => " << str.substr(0 ,10) << std::endl;
		return 1;
	}
	
	switch (month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12: {
			if (day < 1 || day > 31) {
				std::cerr << "Error: bad input => " << str.substr(0 ,10) << std::endl;
				return 1;
			}
			break;
		}
		case 4: case 6: case 9: case 11: {
			if (day < 1 || day > 30) {
				std::cerr << "Error: bad input => " << str.substr(0 ,10) << std::endl;
				return 1;
			}
			break;
		}
		case 2: {
			int maxDay = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 29 : 28;
			if (day < 1 || day > maxDay) {
				std::cerr << "Error: bad input => " << str.substr(0 ,10) << std::endl;
				return 1;
			}
			break;
		}
		default:
			return 1;
	}

	int i = 1;
	if (str.length() > 12 && str.at(10) == ' ' && str.at(11) == '|' && str.at(12) == ' ') {
		i += 2;
	}

	bool isInput = (i > 1);

	value = std::strtod(end + i, &end);
	if (value < 0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return 1;
	}

	else if (isInput && value > 1000) {
		std::cerr << "Error: too large a number." << std::endl;
		return 1;
	}
	if (*end != '\0') {
		std::cerr << "Error: bad input => " << str << std::endl;
		return 1;
	}
	
	return 0;
}

int BitcoinExchange::mappingData(std::map<std::string, double> &data) {
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

	double exRate;

	while (std::getline(fd, str)) {
		if (str.empty() || validateDate(str, exRate)) {
			continue;
		}

		data[str.substr(0, 10)] = exRate;
	}
	return 0;
}

int BitcoinExchange::exchange(std::map<std::string, double> &data, std::ifstream &fd) {
	std::string str;
	double		value;

	std::getline(fd, str);
	if (str.compare("date | value")) {
		std::cerr << "Error: Expected \"date | value\" at the beginning of the input file!" << std::endl;
		return 1;
	}

	while (std::getline(fd, str)) {
		if (validateDate(str, value)) {
			continue;
		}

		std::string date = str.substr(0, 10);

		if (VERBOSE) {
			std::cout << date << " | " << value << std::endl;
		}

		std::map<std::string, double>::iterator it = data.lower_bound(date);

		if (it == data.end()) {
			--it;
		}
		else if (it->first != date) {
			if (it == data.begin()) {
				std::cerr << "Error: no valid date." << std::endl;
				continue;
			}
			--it;
		}

		std::cout << date << " => " << value << " = " << value * it->second << std::endl;
	}
	return 0;
}