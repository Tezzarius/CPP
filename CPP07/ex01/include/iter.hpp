#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *ptr, const unsigned int len, void (*f)(T &));

template <typename T>
void iter(const T *ptr, const unsigned int len, void (*f)(const T &));

//main test templates
template <typename T>
void print(T &value);

template <typename T>
void printConst(const T &value);

template <typename T>
void addOne(T &value);

# include "iter.tpp"

#endif
