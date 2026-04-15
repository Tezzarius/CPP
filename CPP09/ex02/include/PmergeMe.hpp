#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# ifndef VERBOSE
#  define VERBOSE 0
# endif

# include <iostream>
# include <string>
# include <cstdlib>
# include <climits>
# include <vector>

class PmergeMe {
	private:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

	public:
		static int parseInput(std::vector<long> &vec, const std::string &str);
};


#endif