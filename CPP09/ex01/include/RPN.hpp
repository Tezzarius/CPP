#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <iostream>
# include <stack>
# include <list>
# include <cstdlib>
# include <climits>

class RPN {
	private:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		static int useOperator(std::stack<int, std::list<int> > &list, char op);
		
	public:
		static int	reversePolishNotation(std::stack<int, std::list<int> > &list, const std::string &str);
};


#endif