#include "ScalarConverter.hpp"

void castInt(double &num) {
	size_t x = 0;
	int i = static_cast<int>(num);
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);
	if (!isprint(c)) {
		x = 1;
	}
	if (num > INT_MAX || num < INT_MIN) {
		x = 2;
	}
	printOutput(c, i, f, d, x);
}

void castFloat(double &num) {
	size_t x = 0;
	float f = static_cast<float>(num);
	int i = static_cast<int>(f);
	char c = static_cast<char>(f);
	double d = static_cast<double>(f);
	if (!isprint(c)) {
		x = 1;
	}
	if (num > INT_MAX || num < INT_MIN) {
		x = 2;
	}
	printOutput(c, i, f, d, x);
}

void castDouble(double &num) {
	size_t x = 0;
	double d = num;
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);
	if (!isprint(c)) {
		x = 1;
	}
	if (num > INT_MAX || num < INT_MIN) {
		x = 2;
	}
	printOutput(c, i, f, d, x);
}

void castPseudoFloat(double &num) {
	float f = static_cast<float>(num);
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);
	printOutput(c, i, f, d, 2);
}

void castPseudoDouble(double &num) {
	double d = static_cast<double>(num);
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);
	printOutput(c, i, f, d, 2);
}

void casting(double d, Type t) {
	switch (t) {
		case 0: return;
		case 1:	return castInt(d);
		case 2:	return castFloat(d);
		case 3: return castDouble(d);
		case 4: return castPseudoFloat(d);
		case 5: return castPseudoDouble(d);
		case 6: return;
	}
}
