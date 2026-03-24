#include "Span.hpp"
#include <algorithm>
#include <limits>

Span::Span() {

}

Span::Span(unsigned int num) : N(num) {

}

Span::Span(const Span &other) {
	N = other.N;
	store = other.store;
}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		N = other.N;
		store = other.store;
	}
	return *this;
}

Span::~Span() {

}

void Span::addNumber(int num) {
	if (store.size() < N)
		store.push_back(num);
	else
		throw std::runtime_error("Span is already full!");
}

int abs(int num) {
	if (num < 0)
		return -num;
	return num;
}

unsigned int Span::shortestSpan() const {
	if (store.size() < 2)
		throw std::runtime_error("Not enough elements for a span!");
	std::vector<int> sorted = store;
	std::sort(sorted.begin(), sorted.end());
	unsigned int span = std::numeric_limits<unsigned int>::max();
	for (unsigned int i = 1; i < sorted.size(); i++) {
		unsigned int diff = sorted[i] - sorted[i - 1];
		if (diff < span)
			span = diff;
	}
	return span;
}

unsigned int Span::longestSpan() const {
	if (store.size() < 2)
		throw std::runtime_error("Not enough elements for a span!");
	int min = *std::min_element(store.begin(), store.end());
	int max = *std::max_element(store.begin(), store.end());
	return max - min;
}
