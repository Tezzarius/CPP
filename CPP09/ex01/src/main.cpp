#include "RPN.hpp"

void math(std::stack<int> &s, char op) {
	if (op == ' ')
		return;

	if (s.size() < 2)
		throw std::runtime_error("Error: size");

	double b = s.top(); s.pop();
	double a = s.top(); s.pop();
	double result;

	switch (op) {
		case '+': result = a + b; break;
		case '-': result = a - b; break;
		case '*':
			if ((a * b) > INT_MAX || (a * b) < INT_MIN) throw std::runtime_error("Error");
			result = a * b;
			break;
		case '/':
			if (b == 0) throw std::runtime_error("Error: division by zero");
			result = a / b; break;
		default:
			throw std::runtime_error("Error: no case");
	}
	s.push(result);
}

int main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Error: no input" << std::endl;
		return 1;
	}

	std::stack<int> s;

	try {
		for (int i = 1; av[i]; i++) {
			std::string str = av[i];
			char *end;

			const char *current = str.c_str();
			while (*current != '\0') {

				int num = std::strtol(current, &end, 10);

				if (end == current) {
					math(s, *current);
					current++;
				}
				else {
					if (num < 10 && num >= 0)
						s.push(num);
					else
						throw std::runtime_error("Error");
					current = end;
				}
			}
		}


		if (s.size() != 1)
			throw std::runtime_error("Error: invalid");

		std::cout << s.top() << std::endl;
		s.pop();
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}