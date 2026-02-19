#include "ScalarConverter.hpp"

int isChar(std::string &str) {
	if (str.length() == 1 && !isdigit(str.at(0)) && isprint(str.at(0)))
		return 1;
	return 0;
}

int isPseudo(std::string &str) {
	if (!str.compare("-inff") || !str.compare("+inff") || !str.compare("nanf"))
		return 1;
	if (!str.compare("-inf") || !str.compare("+inf") || !str.compare("nan"))
		return 2;
	return 0;
}

int isFloat(std::string &str) {
	if (str[str.length() - 1] == 'f') {
		int check[2] = {0, 0};
		size_t i = 0;
		if (str.at(i) == '+' || str.at(i) == '-')
			i++;
		for (; str[i]; i++) {
			if (str.at(i) == '.') {
				check[0] += 1;
				if (str[i - 1] && (!isdigit(str.at(i - 1)) || !isdigit(str.at(i + 1))))
					return 0;
			}
			else if (str.at(i) == 'f')
				check[1] += 1;
			else if (!isdigit(str.at(i)))
				return 0;
		}
		if (check[0] == 1 && check[1] == 1)
			return 1;
	}
	return 0;
}

int isIntOrDouble(std::string &str) {
 	if (str.at(0) == '+' || str.at(0) == '-' || isdigit(str.at(0))) {
		size_t i = 0;
		int check = 0;
		if (str.at(0) == '+' || str.at(0) == '-')
			i++;
		for (; str[i]; i++)
			if (!isdigit(str.at(i))) {
				if (str.at(i) == '.' && str[i + 1] && isdigit(str.at(i + 1)) && isdigit(str.at(i - 1)))
					check += 1;
				else
					return 0;
			}
		switch (check) {
			case 0:	return 2;
			case 1: return 1;
		}
	}
	return 0;
}

Type detectType(std::string &str) {
	if (isChar(str))
		return CHAR;
	if (isPseudo(str) == 1)
		return PSEUDO_FLOAT;
	else if (isPseudo(str) == 2)
		return PSEUDO_DOUBLE;
	if (isFloat(str))
		return FLOAT;
	if (isIntOrDouble(str) == 1)
		return DOUBLE;
	else if(isIntOrDouble(str) == 2)
		return INT;
	return UNKNOWN;
}