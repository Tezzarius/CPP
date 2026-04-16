#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>
# include <algorithm>
# include <limits>

class Span {
	private:
		unsigned int		_N;
		std::vector<int>	_store;
	
		int abs(int num);

	public:
		Span();
		Span(unsigned int);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int);

		template <typename Iterator>
		void addRange(Iterator begin, Iterator end) {
			if (_store.size() + std::distance(begin, end) > _N)
				throw std::runtime_error("Not enough space!");
			_store.insert(_store.end(), begin, end);
		}

		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
};

#endif
