#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
#include <climits>
#include <limits>
#include <iomanip>
#include <cmath>
#include <cstdlib>

enum Type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO_FLOAT,
	PSEUDO_DOUBLE,
	UNKNOWN
};

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();
	public:
		static void convert(std::string);
};

Type detectType(std::string &str);
void casting(double d, Type t);
std::string printType(Type t);
void printOutput(char c, int i, float f, double d, size_t x);

#endif