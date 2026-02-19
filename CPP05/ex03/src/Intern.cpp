#include "Debug.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
	if (VERBOSE)
		std::cout << COLOUR << "Intern was created" << RESET << std::endl;
}
Intern::Intern(const Intern &other) {
	(void)other;
	if (VERBOSE)
		std::cout << COLOUR << "Intern was copied" << RESET << std::endl;
}
Intern &Intern::operator=(const Intern &other) {
	(void)other;
	if (VERBOSE)
		std::cout << COLOUR << "Intern was assignedd" << RESET << std::endl;
	return *this;
}
Intern::~Intern() {
	if (VERBOSE)
		std::cout << COLOUR << "Intern was destroyed" << RESET << std::endl;
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