#include "RPN.hpp"

static void useOperator(std::stack<int> &s, char op) {
	if (op == ' ')
		return;

	if (s.size() < 2)
		throw std::runtime_error("Error: stack size to low");

	double b = s.top(); s.pop();
	double a = s.top(); s.pop();
	double result;

	switch (op) {
		case '+': result = a + b; break;
		case '-': result = a - b; break;
		case '*':
			if ((a * b) > INT_MAX || (a * b) < INT_MIN) throw std::runtime_error("Error: result out of bound");
			result = a * b;
			break;
		case '/':
			if (b == 0) throw std::runtime_error("Error: division by zero");
			result = a / b; break;
		default:
			throw std::runtime_error("Error: invalid character");
	}
	s.push(result);
}

void reversePolishNotation(std::stack<int> &s, char **av) {
	for (int i = 1; av[i]; i++) {
		std::string str = av[i];
		char *end;

		const char *current = str.c_str();
		while (*current != '\0') {

			int num = std::strtol(current, &end, 10);

			if (end == current) {
				useOperator(s, *current);
				current++;
			}
			else {
				if (num < 10 && num >= 0)
					s.push(num);
				else
					throw std::runtime_error("Error: input number to high");
				current = end;
			}
		}
	}


	if (s.size() != 1)
		throw std::runtime_error("Error: stack size to high");

	std::cout << s.top() << std::endl;
	s.pop();
}