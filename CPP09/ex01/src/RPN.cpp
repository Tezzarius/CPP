#include "RPN.hpp"

RPN::RPN() {

}

RPN::RPN(const RPN &other) : _stack(other._stack) {

}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other)
		_stack = other._stack;
	return *this;
}

RPN::~RPN() {

}

static int useOperator(std::stack<int> &stack, char op) {
	if (op == ' ')
		return 0;

	if (stack.size() < 2) {
		std::cerr << "Error: stack size to low" << std::endl;
		return 1;
	}

	double b = stack.top(); stack.pop();
	double a = stack.top(); stack.pop();
	double result;

	switch (op) {
		case '+': result = a + b; break;
		case '-': result = a - b; break;
		case '*':
			if ((a * b) > INT_MAX || (a * b) < INT_MIN) {
				std::cerr << "Error: result out of bound" << std::endl;
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

int RPN::reversePolishNotation(std::string str) {
	char *end;

	const char *current = str.c_str();
	while (*current != '\0') {
		int num = std::strtol(current, &end, 10);

		if (end == current) {
			if (useOperator(_stack, *current))
				return 1;
			current++;
		}
		else {
			if (num < 10 && num >= 0)
				_stack.push(num);
			else {
				std::cerr << "Error: input number to high" << std::endl;
				return 1;
			}
			current = end;
		}
	}


	if (_stack.size() != 1) {
		std::cerr << "Error: stack size to high" << std::endl;
		return 1;
	}

	std::cout << _stack.top() << std::endl;
	_stack.pop();
	return 0;
}