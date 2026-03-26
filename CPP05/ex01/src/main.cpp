#include "Form.hpp"

int main() {
	Bureaucrat *Ted = NULL;
	Bureaucrat *Karl = NULL;
	Bureaucrat *Hans = NULL;
	Form alpha("alpha", 5, 2);
	Form beta("beta", 10, 4);

	try {
		Hans = new Bureaucrat("Hans", 0);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Hans = new Bureaucrat("Hans", 160);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Ted = new Bureaucrat("Ted", 3);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	try {
		Karl = new Bureaucrat("Karl", 150);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	if (Hans) {
		std::cout << *Hans << std::endl;
	}
	if (Ted) {
		std::cout << *Ted << std::endl;
	}
	if (Karl) {
		std::cout << *Karl << std::endl;
	}

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

		try {
			Ted->signForm(alpha);
			std::cout << alpha << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	if (Karl) {
		try {
			Karl->signForm(beta);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		
		std::cout << beta << std::endl;
	}

	delete Hans;
	delete Ted;
	delete Karl;
}