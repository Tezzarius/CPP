#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	Bureaucrat *Asterix = NULL;
	Bureaucrat *Obelix = NULL;
	Bureaucrat *Miraculix = NULL;
	Bureaucrat *Stupidix = NULL;
	PresidentialPardonForm Alpha("Alpha");
	ShrubberyCreationForm Beta("Beta");
	RobotomyRequestForm Gamma("Gamma");

	try {
		Asterix = new Bureaucrat("Asterix", 40);
		std::cout << *Asterix << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Obelix = new Bureaucrat("Obelix", 135);
		std::cout << *Obelix << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Miraculix = new Bureaucrat("Miraculix", 4);
		std::cout << *Miraculix << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Stupidix = new Bureaucrat("Stupidix", 0);
		std::cout << *Stupidix << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Stupidix = new Bureaucrat("Stupidix", 160);
		std::cout << *Stupidix << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Stupidix = new Bureaucrat("Stupidix", 140);
		std::cout << *Stupidix << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;

	if (Stupidix) {
		try {
			Stupidix->signForm(Alpha);
			Stupidix->executeForm(Alpha);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << Alpha << std::endl;
	}

	if (Miraculix) {
		try {
			Miraculix->signForm(Alpha);
			Miraculix->executeForm(Alpha);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	if (Stupidix) {
		try {
			Stupidix->signForm(Beta);
			Stupidix->executeForm(Beta);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << Beta << std::endl;
	}

	if (Obelix) {
		try {
			Obelix->signForm(Beta);
			Obelix->executeForm(Beta);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	if (Stupidix) {
		try {
			Stupidix->signForm(Gamma);
			Stupidix->executeForm(Gamma);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << Gamma << std::endl;
	}

	if (Asterix) {
		try {
			Asterix->signForm(Gamma);
			for (int i = 0; i < 10; i++)
				Asterix->executeForm(Gamma);
		} catch (std::exception &e) {
			std::cout <<e.what() << std::endl;
		}
	}

	if(Stupidix) {
		delete Stupidix;
	}
	if (Asterix) {
		delete Asterix;
	}
	if (Obelix) {
		delete Obelix;
	}
	if (Miraculix) {
		delete Miraculix;
	}
}