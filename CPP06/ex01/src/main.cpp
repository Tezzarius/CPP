#include "Serializer.hpp"
#include <iostream>

int main() {
	Data data;
	data.num = 9;
	Data *ptr = &data;
	std::cout << "Data value:       " << data.num << std::endl
		<< "Original pointer: " << ptr << std::endl;
	uintptr_t raw = Serializer::serialize(ptr);
	std::cout << "Serialized:       " << raw << std::endl;
	Data *newPtr = Serializer::deserialize(raw);
	std::cout << "Deserialized:     " << newPtr << std::endl;
	return 0;
}