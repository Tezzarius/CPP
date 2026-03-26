#include "Base.hpp"
#include "emptyClasses.hpp"
#include <cstdlib>

Base::~Base() {
	
}

Base *generate() {
	int val = rand() % 3;
	switch (val) {
		case 0: std::cout << "Created A" << std::endl;
			return new A;
		case 1: std::cout << "Created B" << std::endl;
			return new B;
		case 2: std::cout << "Created C" << std::endl;
			return new C;
		default : return NULL;
	}
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "Pointer type: A" << std::endl;
	}
	else if (dynamic_cast<B*>(p)) {
		std::cout << "Pointer type: B" << std::endl;
	}
	else if (dynamic_cast<C*>(p)) {
		std::cout << "Pointer type: C" << std::endl;
	}
}

void identify(Base &p) {
	try {
		A &a = dynamic_cast<A&>(p);
		std::cout << "Reference type: A " << std::endl;
		(void)a;
	} catch (...) {

	}
	try {
		B &a = dynamic_cast<B&>(p);
		std::cout << "Reference type: B" << std::endl;
		(void)a;
	} catch (...) {

	}
	try {
		C &a = dynamic_cast<C&>(p);
		std::cout << "Reference type: C" << std::endl;
		(void)a;
	} catch (...) {

	}
}