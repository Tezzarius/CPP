#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# ifndef EXPLAIN
#  define EXPLAIN 0
# endif

# ifndef VERBOSE
#  define VERBOSE 0
# endif

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include <climits>
# include <vector>
# include <deque>
# include <ctime>

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
		void	printContainer(std::string str);

		template <typename T>
		void	fordJohnson(T &container);

		void	printResult(double timeVector, double timeDeque);

		long	min(long &a, long &b);
		long	max(long &a, long &b);
};

# include "PmergeMe.tpp"

#endif