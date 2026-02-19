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

std::string printType(Type t) {
	switch (t) {
		case 0: return "CHAR";
		case 1: return "INT";
		case 2: return "FLOAT";
		case 3: return "DOUBLE";
		case 4: return "PSEUDO_FLOAT";
		case 5: return "PSEUDO_DOUBLE";
		case 6: return "UNKNOWN";
	}
}

void ScalarConverter::convert(std::string str) {
	Type t = detectType(str);
	if (VERBOSE)
		std::cout << std::endl << COLOUR << "Input type: " << printType(t) << RESET << std::endl;
	if (t < 6)
		casting(d, t);
	else
		std::cout << "Unknown input!" << std::endl;
}
