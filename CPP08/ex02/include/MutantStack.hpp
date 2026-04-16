#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack();
		MutantStack(const T &);
		MutantStack &operator=(const T &);
		~MutantStack();

		typedef typename
		std::stack<T>::container_type::iterator	iterator;
		typedef typename
		std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename
		std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename
		std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator	begin();
		iterator	end();
};

# include "MutantStack.tpp"

#endif
