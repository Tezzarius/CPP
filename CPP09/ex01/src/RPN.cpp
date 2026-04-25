#include "RPN.hpp"

int RPN::useOperator(std::stack<int, std::list<int> > &list, char op) {
	if (op == ' ')
		return 0;

	if (list.size() < 2) {
		std::cerr << "Error: list size to low" << std::endl;
		return 1;
	}

	long b = list.top(); list.pop();
	long a = list.top(); list.pop();
	long result;

	switch (op) {
		case '+': result = a + b; break;
		case '-': result = a - b; break;
		case '*':
			if ((a * b) > INT_MAX || (a * b) < INT_MIN) {
				std::cerr << "Error: int overflow" << std::endl;
				return 1;
			}
			result = a * b;
			break;
		case '/':
			if (b == 0) {
				std::cerr << "Error: division by zero" << std::endl;
				return 1;
			}
			result = a / b; break;
		default: {
			std::cerr << "Error: invalid character" << std::endl;
			return 1;
		}
	}
	list.push(result);
	return 0;
}

int RPN::reversePolishNotation(std::stack<int, std::list<int> > &list, const std::string &str) {
	char *end;

	const char *current = str.c_str();
	while (*current != '\0') {
		int num = std::strtol(current, &end, 10);

		if (end == current) {
			if (useOperator(list, *current))
				return 1;
			current++;
		}
		else {
			if (num < 10 && num >= 0) {
				list.push(num);
			}
			else {
				std::cerr << "Error: input number to high" << std::endl;
				return 1;
			}
			current = end;
		}
	}


	if (list.size() != 1) {
		std::cerr << "Error: list size to high" << std::endl;
		return 1;
	}

	std::cout << list.top() << std::endl;
	list.pop();
	return 0;
}