#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
#include <climits>
#include <limits>
#include <iomanip>
#include <cmath>

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

#endif