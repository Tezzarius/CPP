#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
#include <stdexcept>

class Span {
	private:
		unsigned int N;
		std::vector<int> store;
	public:
		Span();
		Span(unsigned int);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int);
		template <typename Iterator>
		void addRange(Iterator begin, Iterator end) {
			if (store.size() + std::distance(begin, end) > N)
				throw std::runtime_error("Not enough space!");
			store.insert(store.end(), begin, end);
		}
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
};

#endif