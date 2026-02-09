#include "Bureaucrat.hpp"

int main() {
	Bureaucrat *Ted = NULL;
	Bureaucrat *Karl = NULL;
	Bureaucrat *Test = NULL;

	try {
		Test = new Bureaucrat("Test", 0);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Test = new Bureaucrat("Test", 160);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Ted = new Bureaucrat("Ted", 3);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}	try {
		Karl = new Bureaucrat("Karl", 150);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	if (Test)
		std::cout << *Test << std::endl;
	if (Ted)
		std::cout << *Ted << std::endl;
	if (Karl)
		std::cout << *Karl << std::endl;

	if (Ted) {
		std::cout << "Ted will be promoted by 2 grades." << std::endl;
		Ted->incrementGrade();
		Ted->incrementGrade();
		std::cout << *Ted << std::endl;
		try {
			Ted->incrementGrade();
			std::cout << *Ted << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	delete Test;
	delete Ted;
	delete Karl;
}