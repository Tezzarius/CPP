#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void iter(T *arr, const unsigned int len, void (*f)(T &)) {
	for (unsigned int i = 0; i < len; i++) {
		f(arr[i]);
	}
}

template <typename T>
void iter(const T *arr, const unsigned int len, void (*f)(const T &)) {
	for (unsigned int i = 0; i < len; i++) {
		f(arr[i]);
	}
}

#endif