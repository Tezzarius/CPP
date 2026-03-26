#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {

}
Intern::Intern(const Intern &other) {
	(void)other;
}
Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return *this;
}
Intern::~Intern() {

}

AForm *Intern::makeForm(std::string form, std::string name) {
	std::string forms[3];

	forms[0] = "presidential pardon";
	forms[1] = "robotomy request";
	forms[2] = "shrubbery creation";

	int i;
	for (i = 0; i < 3 && forms[i].compare(form); i++);
	switch (i) {
		case 0:
			std::cout << "Intern creates " << form << std::endl;
			return new PresidentialPardonForm(name);
		case 1:
			std::cout << "Intern creates " << form << std::endl;
			return new RobotomyRequestForm(name);
		case 2:
			std::cout << "Intern creates " << form << std::endl;
			return new ShrubberyCreationForm(name);
		default:
			std::cout << "Intern couldn't create " << form << ", this form doesn't exist." << std::endl;
	}
	return NULL;
}