#include "Span.hpp"

Span::Span() {

}

Span::Span(unsigned int num) : _N(num) {

}

Span::Span(const Span &other) {
	_N = other._N;
	_store = other._store;
}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		_N = other._N;
		_store = other._store;
	}
	return *this;
}

Span::~Span() {

}

void Span::addNumber(int num) {
	if (_store.size() < _N) {
		_store.push_back(num);
	}
	else {
		throw std::runtime_error("Span is already full!");
	}
}

int Span::abs(int num) {
	if (num < 0) {
		return -num;
	}
	return num;
}

unsigned int Span::shortestSpan() const {
	if (_store.size() < 2) {
		throw std::runtime_error("Not enough elements for a span!");
	}
	std::vector<int> sorted = _store;
	std::sort(sorted.begin(), sorted.end());
	unsigned int span = std::numeric_limits<unsigned int>::max();
	for (unsigned int i = 1; i < sorted.size(); i++) {
		unsigned int diff = sorted[i] - sorted[i - 1];
		if (diff < span) {
			span = diff;
		}
	}
	return span;
}

unsigned int Span::longestSpan() const {
	if (_store.size() < 2) {
		throw std::runtime_error("Not enough elements for a span!");
	}
	int min = *std::min_element(_store.begin(), _store.end());
	int max = *std::max_element(_store.begin(), _store.end());
	return max - min;
}
