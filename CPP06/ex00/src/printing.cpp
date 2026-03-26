#include "ScalarConverter.hpp"

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

void printOutput(char c, int i, float f, double d, size_t x) {
	std::cout << "char: ";
	switch (x) {
		case 0: std::cout << c << std::endl;
				break;
		case 1: std::cout << "Non displayable" << std::endl;
				break;
		case 2: std::cout << "impossible" << std::endl;
	}
	std::cout << "int: ";
	if (x == 3 || x == 2) {
		std::cout << "impossible" << std::endl;
	}
	else {
		std::cout << i << std::endl;
	}
	if (i == f) {
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;		
	}
	else {
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}

}