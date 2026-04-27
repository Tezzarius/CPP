#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# ifndef EXPLAIN
#  define EXPLAIN 0
# endif

# ifndef VERBOSE
#  define VERBOSE 0
# endif

# include <iostream>
# include <string>
# include <cstdlib>
# include <climits>
# include <vector>
# include <deque>

struct Pair {
	int small;
	int large;
};

class PmergeMe {
	private:
		std::vector<long>	_vec;
		std::deque<long>	_deq;

	public:
		PmergeMe(char **av);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void sortAndPrint();
		
		private:
		void	parseInput(const std::string &str);
		void	fordJohnsonVector();
		void	fordJohnsonDeque();
		void	printBefor();
		void	printAfter();
};


#endif