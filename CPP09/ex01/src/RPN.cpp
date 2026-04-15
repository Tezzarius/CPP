#include "RPN.hpp"

int RPN::useOperator(std::stack<int> &stack, char op) {
	if (op == ' ')
		return 0;

	if (stack.size() < 2) {
		std::cerr << "Error: stack size to low" << std::endl;
		return 1;
	}

	long b = stack.top(); stack.pop();
	long a = stack.top(); stack.pop();
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
	stack.push(result);
	return 0;
}

int RPN::reversePolishNotation(const std::string &str) {
	std::stack<int> stack;
	char *end;

	const char *current = str.c_str();
	while (*current != '\0') {
		int num = std::strtol(current, &end, 10);

		if (end == current) {
			if (useOperator(stack, *current))
				return 1;
			current++;
		}
		else {
			if (num < 10 && num >= 0)
				stack.push(num);
			else {
				std::cerr << "Error: input number to high" << std::endl;
				return 1;
			}
			current = end;
		}
	}


	if (stack.size() != 1) {
		std::cerr << "Error: stack size to high" << std::endl;
		return 1;
	}

	std::cout << stack.top() << std::endl;
	stack.pop();
	return 0;
}