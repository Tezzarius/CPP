#include "Debug.hpp"
#include "ScalarConverter.hpp"
#include <sstream>

ScalarConverter::ScalarConverter() {

}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {

}

void castChar(std::string str) {
	size_t x = 0;
	char c = str.at(0);
	if (!isprint(c))
		x = 1;
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);
	printOutput(c, i, f, d, x);
}

void ScalarConverter::convert(std::string str) {
	Type t = detectType(str);
	if (VERBOSE)
		std::cout << std::endl << COLOUR << "Input type: " << printType(t) << RESET << std::endl;
	double num;
	if (t < 6) {
		char *end;
		num = std::strtod(str.c_str(), &end);
		if (t == 0)
			castChar(str);
		casting(num, t);
		if (VERBOSE)
			std::cout << COLOUR << "Input as double: " << num << RESET << std::endl << std::endl;
	}
	else
		std::cout << "Unknown input!" << std::endl;
}
