#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <iostream>
# include <stack>
# include <exception>
# include <cstdlib>
# include <climits>

class RPN {
	private:
		std::stack<int> _stack;
		
	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		int	reversePolishNotation(std::string str);
};


#endif