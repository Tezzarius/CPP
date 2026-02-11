#include "AForm.hpp"

int main() {
	Bureaucrat *Asterix = NULL;
	Bureaucrat *Obelix = NULL;
	Bureaucrat *Hans = NULL;
	AForm alpha("alpha", 5, 2);
	AForm beta("beta", 10, 4);

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
		Asterix = new Bureaucrat("Asterix", 3);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}	try {
		Obelix = new Bureaucrat("Obelix", 150);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	if (Hans)
		std::cout << *Hans << std::endl;
	if (Asterix)
		std::cout << *Asterix << std::endl;
	if (Obelix)
		std::cout << *Obelix << std::endl;

	if (Asterix) {
		std::cout << "Asterix will be promoAsterix by 2 grades." << std::endl;
		Asterix->incrementGrade();
		Asterix->incrementGrade();
		std::cout << *Asterix << std::endl;
		try {
			Asterix->incrementGrade();
			std::cout << *Asterix << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			Asterix->signForm(alpha);
			std::cout << alpha << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	if (Obelix) {
		try {
			Obelix->signForm(beta);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << beta << std::endl;
	}

	delete Hans;
	delete Asterix;
	delete Obelix;
}