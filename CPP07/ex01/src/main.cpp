#include "iter.hpp"
#include <iostream>
#include <string>

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

int main() {
	int intArray[5] = {1, 2, 3, 4, 5};
	std::string strArray[3] = {"Just", "a", "Test"};

	std::cout << "Print int array:" << std::endl;
	iter(intArray, 5, print);
	std::cout << std::endl;

	std::cout << std::endl << "Add 1 to int array:" << std::endl;
	iter(intArray, 5, addOne);
	iter(intArray, 5, print);
	std::cout << std::endl;

	std::cout << std::endl << "Print string array:" << std::endl;
	iter(strArray, 3, printConst);
	std::cout << std::endl;

	return 0;
}