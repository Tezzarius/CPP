#include "Base.hpp"
#include "emptyClasses.hpp"
#include <ctime>
#include <cstdlib>

int main() {
	std::srand(std::time(0));
	for (int i = 0; i < 10; i++) {
		Base *p = generate();
		identify(p);
		identify(*p);
		std::cout << std::endl;
		delete p;
	}
}