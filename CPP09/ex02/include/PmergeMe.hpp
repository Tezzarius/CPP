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
	long small;
	long large;
};

class PmergeMe {
	private:
	std::vector<long>	_vector;
	std::deque<long>	_deque;
	bool				_explain;
	size_t				_comparisons;

	public:
		PmergeMe(char **av);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void sortAndPrint();
		
	private:
		void	parseInput(const std::string &str);
		void	printContainer(std::string str);
		void	printResult(double timeVector, double timeDeque);
		
		template <typename T>
		void	fordJohnson(T &container, int depth);
		
		template <typename T>
		void	binaryInsert(T &mainChain, int valuem, size_t right);

		template <typename T>
		size_t	findPosition(T &mainChain, int target);
		
		std::vector<size_t>	generateJacobsOrder(size_t size);
};

# include "PmergeMe.tpp"

#endif
