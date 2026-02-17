#include "ScalarConverter.hpp"
#include <climits>
#include <limits>
#include <iomanip>
#include <cmath>

void convertFromChar(std::string str) {
	char c = (char)str.at(0);
	int i = (int)c;
	float f = (float)c;
	double d = (double)c;
	std::cout << "char: " << (std::isprint(c) ? std::string(1, c) : "Non displayable") << std::endl
		<< "int: " << i << std::endl
		<< "float: " << f << ".0f" << std::endl
		<< "double: " << d << ".0" << std::endl;
}

int checkInt(std::string str) {
	for (int i = 0; str[i]; i++) {
		if (!std::isdigit(str.at(i)))
			break;
		if (i + 1 == (int)str.length())
			return 1;
	}
	return 0;
}

int strtoi(std::string str) {
	int i;
	long neg = 1;
	long res = 0;
	for (i = 0; str[i] && (str[i] == '+' || str[i] == '-'); i++)
		if (str[i] == '-')
			neg = -1;
	for (; str[i]; i++) {
		res *= 10;
		res += str[i] - '0';
	}
	res *= neg;
	return res;
}

void convertFromInt(std::string str) {
	long i = strtoi(str);
	char c = (char)i;
	float f = (float)i;
	double d = (double)i;
	std::cout << i << std::endl;
	std::cout << "char: " << ((std::isprint(c)) ? (std::string (1, c)) : "Non displayable") << std::endl
		<< "int: " << ((i > INT_MIN && i < INT_MAX) ? str : "impossible") << std::endl;
	if (f == std::floor(f))
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl
			<< "double: " << d <<std::endl;
	else
		std::cout << std::setprecision(15) << f << "f" << std::endl
			<< "double: " << d <<std::endl;
}

void ScalarConverter::convert(std::string str) {
	if (str.length() == 1 && !std::isdigit(str.at(0))){
		convertFromChar(str);
	}
	if (checkInt(str)) {
		convertFromInt(str);
	}
}