#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <iostream>
# include <stack>
# include <cstdlib>
# include <climits>

class RPN {
	private:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		static int useOperator(std::stack<int> &stack, char op);
		
	public:
		static int	reversePolishNotation(const std::string &str);
};


#endif