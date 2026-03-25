#include "Debug.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string name)
	: AForm(name, 145, 137) {
	if (VERBOSE)
		std::cout << COLOUR << name << " was created" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other) {
	if (VERBOSE)
		std::cout << COLOUR << _name << " was copied" << RESET << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other)
		_isSigned = other._isSigned;
	if (VERBOSE)
		std::cout << COLOUR << _name << " was assigned" << RESET << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	if (VERBOSE)
		std::cout << COLOUR << _name << " was destroyed" << RESET << std::endl;
}

void printAsciiTree(std::ofstream &outfile);

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!getIsSigned())
		throw FormNotSignedException(getName());
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException(getName());
	std::string filename = getName() + "_shrubbery";
	std::ofstream outfile(filename.c_str());
	if (!outfile.is_open()) {
		std::cout << "Error: Can't create " << filename << std::endl;
		return;
	}
	printAsciiTree(outfile);
}

void printAsciiTree(std::ofstream &outfile) {
	outfile
	<< "ex02" << std::endl
	<< "├── dep" << std::endl
	<< "│    ├── AForm.d" << std::endl
	<< "│    ├── Bureaucrat.d" << std::endl
	<< "│    ├── Intern.d" << std::endl
	<< "│    ├── main.d" << std::endl
	<< "│    ├── PresidentialPardonForm.d" << std::endl
	<< "│    ├── RobotomyRequestForm.d" << std::endl
	<< "│    └── ShrubberyCreationForm.d" << std::endl
	<< "├── include" << std::endl
	<< "│    ├── AForm.hpp" << std::endl
	<< "│    ├── Bureaucrat.hpp" << std::endl
	<< "│    ├── Debug.hpp" << std::endl
	<< "│    ├── Intern.hpp" << std::endl
	<< "│    ├── PresidentialPardonForm.hpp" << std::endl
	<< "│    ├── RobotomyRequestForm.hpp" << std::endl
	<< "│    └── ShrubberyCreationForm.hpp" << std::endl
	<< "├── obj" << std::endl
	<< "│    ├── AForm.o" << std::endl
	<< "│    ├── Bureaucrat.o" << std::endl
	<< "│    ├── Intern.o" << std::endl
	<< "│    ├── main.o" << std::endl
	<< "│    ├── PresidentialPardonForm.o" << std::endl
	<< "│    ├── RobotomyRequestForm.o" << std::endl
	<< "│    └── ShrubberyCreationForm.o" << std::endl
	<< "├── src" << std::endl
	<< "│    ├── AForm.cpp" << std::endl
	<< "│    ├── Bureaucrat.cpp" << std::endl
	<< "│    ├── Intern.cpp" << std::endl
	<< "│    ├── maint.cpp" << std::endl
	<< "│    ├── PresidentialPardonForm.cpp" << std::endl
	<< "│    ├── RobotomyRequestForm.cpp" << std::endl
	<< "│    └── ShrubberyCreationForm.cpp" << std::endl
	<< "├── Makefile" << std::endl
	<< "├── PermitA38" << std::endl;
}
