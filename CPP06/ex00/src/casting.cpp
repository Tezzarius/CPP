#include "Debug.hpp"
#include "ScalarConverter.hpp"

void castChar(double d) {
	(void)d;
}

void castInt(double d) {
	(void)d;
}

void castFloat(double d) {
	(void)d;
}

void castDouble(double d) {
	(void)d;
}

void castPseudoFloat(double d) {
	(void)d;
}

void castPseudoDouble(double d) {
	(void)d;
}

void casting(double d, Type t) {
	switch (t) {
		case 0: return castChar(d);
		case 1:	return castInt(d);
		case 2:	return castFloat(d);
		case 3: return castDouble(d);
		case 4: return castPseudoFloat(d);
		case 5: return castPseudoDouble(d);
		case 6: return;
	}
}
