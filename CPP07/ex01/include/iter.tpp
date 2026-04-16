#include "iter.hpp"

template <typename T>
void iter(T *ptr, const unsigned int len, void (*f)(T &)) {
	for (unsigned int i = 0; i < len; i++) {
		f(ptr[i]);
	}
}

template <typename T>
void iter(const T *ptr, const unsigned int len, void (*f)(const T &)) {
	for (unsigned int i = 0; i < len; i++) {
		f(ptr[i]);
	}
}

template <typename T>
void print(T &value) {
	std::cout << value << " ";
}

template <typename T>
void printConst(const T &value) {
	std::cout << value << " ";
}

template <typename T>
void addOne(T &value) {
	value += 1;
}
